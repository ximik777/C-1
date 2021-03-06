#ifndef __ADDITIONALHEADERSEGMENT_H__
#define __ADDITIONALHEADERSEGMENT_H__

#include "ByteBuffer.h"
#include <string>
using namespace std;

enum AdditionalHeaderSegmentType {
	/**
	 * This type of AHS MUST NOT be used if the CDBLength is
	 * less than 17. The length includes the reserved byte 3.
	 */
	EXTENDED_CDB = 1,

	/**
	 * The Expected Bidirectional Read Data Length. But this is not good
	 * documented in the iSCSI Protocol (RFC3720).
	 */
	EXPECTED_BIDIRECTIONAL_READ_DATA_LENGTH,
};

/**
 * AdditionalHeaderSegment
 * This class encapsulate an Additional Header Segment (AHS) defined in iSCSI Protocol (RFC3720).
 * It provides all methods to serialize and deserialize such an AHS. Further there are getter methods to
 * access the specific data, which is contained in this AHS.
 */
class AdditionalHeaderSegment {
public:
    /**
     * Factor, which must be muliplied with the totalAHSLength contained in a
     * BasicHeaderSegment object.
     */
    const static int AHS_FACTOR = 4;
private:
    /** Offset of the first complete line in the AHS specific field. */
    const static int EXTENDED_CDB_OFFSET = 1;

    /**
     * The length of AHS, if the type of the AHS is the Bidirectional Expected
     * Read-Data Length.
     */
    const static int EXPECTED_BIDIRECTIONAL_LENGTH = 0x0005;

    /**
     * Length of the specific field ByteBuffer, which is expected,
     * if the AHS type is the AdditionalHeaderSegmentType.EXPECTED_BIDIRECTIONAL_READ_DATA_LENGTH
     * .
     */
    const static int EXPECTED_BIDIRECTIONAL_SPECIFIC_FIELD_LENGTH = 5;

    /**
     * This is the size (in bytes) of the AHSLength and the AHSType, which are also
     * included in the serialized AHS form
     * of this object.
     */
    const static int FIX_SIZE_OVERHEAD = 3;

    // --------------------------------------------------------------------------
    // --------------------------------------------------------------------------

    /**
     * This field contains the effective length in bytes of the AHS excluding
     * AHSType and AHSLength and padding, if any. The AHS is padded to the
     * smallest integer number of 4 byte words (i.e., from 0 up to 3 padding
     * bytes).
     */
    short length;

    /**
     * The type of this AHS.
     * @see AdditionalHeaderSegmentType
     */
    int type;

    /**
     * This array contains the informations, which are type specific fields.
     */
    ByteBuffer specificField;

    // --------------------------------------------------------------------------
    // --------------------------------------------------------------------------
public:
    /**
     * Default constructor, creates a new, empty AdditionalHeaderSegment object.
     */
    AdditionalHeaderSegment();
	~AdditionalHeaderSegment();

    /**
     * This method serializes the informations of this AHS object to the byte
     * representation defined by the iSCSI Standard.
     * 
     * @param dst
     *            The destination array to write in.
     * @param offset
     *            The start offset in dst.
     * @return The length of used integers of the serialized form of this AHS
     *         object.
     * @throws InternetSCSIException
     *             If any violation of the iSCSI-Standard emerge.
     */
    int serialize(ByteBuffer dst, int offset);


    /**
     * Extract the informations given by the int array to this Additional Header
     * Segment object.
     * 
     * @param pdu
     *            The Protocol Data Unit to be parsed.
     * @param offset
     *            The offset, where to start in the pdu.
     * @throws InternetSCSIException
     *             If any violation of the iSCSI-Standard emerge.
     */
    void deserialize(ByteBuffer pdu, int offset);

    /**
     * Returns the length of this AHS object. Expected values are greater than 0 and a maximum of
     * 65536
     * 
     * @return The length of this AHS object.
     */
    short getLength();

    /**
     * Returns an array with the type specific fields of this AHS object.
     * 
     * @return The type specific fields.
     */
    ByteBuffer getSpecificField();

    /**
     * Returns the type of this AHS object. Expected values are defined as
     * constants in the class AdditionalHeaderSegmentTypes.
     * 
     * @return The value of this AHS object.
     */
    int getType();

    // --------------------------------------------------------------------------
    // --------------------------------------------------------------------------

    /**
     * Creates a string object with all values for easy debugging.
     * 
     * @return The string with all informations of this AHS.
     */
    string toString();

    /**
     * Clears all the stored content of this AdditionalHeaderSegment object.
     */
    void clear();

    // --------------------------------------------------------------------------
    // --------------------------------------------------------------------------

    /** {@inheritDoc} */
    bool equals(AdditionalHeaderSegment &o);

    /**
     * This method checks the integrity of the this Additional Header Segment
     * object to garantee a valid specification.
     * 
     * @throws InternetSCSIException
     *             If the fields are not valid for this AHS type.
     */
    void checkIntegrity();
};

#endif // __ADDITIONALHEADERSEGMENT_H__
