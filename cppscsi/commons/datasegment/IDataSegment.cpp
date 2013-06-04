#include "IDataSegment.h"
int IDataSegment::deserialize(ByteBuffer src, int len)
{
	return 0;
}

/**
 * This method appends <code>len</code> bytes from the given <code>ByteBuffer</code> at the end of the
 * data buffer of this instance.
 * 
 * @param src
 *            Source <code>ByteBuffer</code> object.
 * @param len
 *            The number of bytes to append from <code>src</code>.
 * @return The number of bytes of the complete data buffer of this instance.
 */
int IDataSegment::append(ByteBuffer src, int len)
{
	return 0;
}

/**
 * This method exports the data buffer to the given <code>ByteBuffer</code> object, which is padded to a
 * integer number of <code>4</code> byte words.
 * 
 * @param dst
 *            Destination <code>ByteBuffer</code> object.
 * @param off
 *            Start position in <code>dst</code>, where to serialize.
 * @return The number of exported bytes (in bytes).
 */
int IDataSegment::serialize(ByteBuffer dst, int off)
{
	return 0;
}

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------

/**
 * Returns an iterator over the chunks of this data segment in proper
 * sequence.
 * 
 * @return an iterator over the chunks of this data segment in proper
 *         sequence.
 */
//IDataSegmentIterator iterator();

/**
 * Returns a <code>SettingsMap</code> instance of this <code>IDataSegment</code> instance. This is only
 * useful with a <code>TextParameterDataSegment</code> instance.
 * 
 * @return The settings of this <code>TextParameterDataSegment</code> instance.
 * @throws InternetSCSIException
 *             if any violation of the iSCSI Standard occurs.
 */
//SettingsMap getSettings();

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------

/**
 * Clears all made settings of this object. After the call of this method,
 * this object can be reused.
 */
void IDataSegment::clear()
{
}

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------

/**
 * Returns the length, which is really used by the <code>dataBuffer</code>.
 * 
 * @return The really used length.
 */
int IDataSegment::getLength()
{
	return 0;
}

/**
 * Sets the data buffer to the given buffer <code>src</code>. Starting from
 * the position <code>offset</code> with length of <code>len</code>.
 * 
 * @param src
 *            The buffer to read from.
 * @param off
 *            The start offset to read from.
 * @param len
 *            The number of bytes to read.
 * @return The number of bytes really read.
 */
int IDataSegment::setDataBuffer(ByteBuffer src, int off, int len)
{
	return 0;
}
