//
// Generated file, do not edit! Created by nedtool 5.0 from veins/modules/application/platooning/messages/UnicastProtocolControlMessage.msg.
//

#ifndef __UNICASTPROTOCOLCONTROLMESSAGE_M_H
#define __UNICASTPROTOCOLCONTROLMESSAGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>veins/modules/application/platooning/messages/UnicastProtocolControlMessage.msg:22</tt> by nedtool.
 * <pre>
 * //
 * // Control message sent from the application layer to the unicast protocol
 * // or vicevarsa
 * //
 * packet UnicastProtocolControlMessage
 * {
 *     //control command requested (e.g., set mac address or fail to send)
 *     int controlCommand;
 *     //value for the control command (e.g., actual mac address)
 *     int commandValue;
 * }
 * </pre>
 */
class UnicastProtocolControlMessage : public ::omnetpp::cPacket
{
  protected:
    int controlCommand;
    int commandValue;

  private:
    void copy(const UnicastProtocolControlMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const UnicastProtocolControlMessage&);

  public:
    UnicastProtocolControlMessage(const char *name=nullptr, int kind=0);
    UnicastProtocolControlMessage(const UnicastProtocolControlMessage& other);
    virtual ~UnicastProtocolControlMessage();
    UnicastProtocolControlMessage& operator=(const UnicastProtocolControlMessage& other);
    virtual UnicastProtocolControlMessage *dup() const {return new UnicastProtocolControlMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getControlCommand() const;
    virtual void setControlCommand(int controlCommand);
    virtual int getCommandValue() const;
    virtual void setCommandValue(int commandValue);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UnicastProtocolControlMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UnicastProtocolControlMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __UNICASTPROTOCOLCONTROLMESSAGE_M_H

