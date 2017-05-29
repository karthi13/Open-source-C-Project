//
// Generated file, do not edit! Created by nedtool 5.0 from veins/modules/application/platooning/messages/PlatooningBeacon.msg.
//

#ifndef __PLATOONINGBEACON_M_H
#define __PLATOONINGBEACON_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>veins/modules/application/platooning/messages/PlatooningBeacon.msg:18</tt> by nedtool.
 * <pre>
 * packet PlatooningBeacon
 * {
 *     //id of the originator
 *     int vehicleId = 0;
 *     //id of the sender. relayerId == vehicleId on first hope
 *     int relayerId = 0;
 *     double acceleration = 0;
 *     double speed = 0;
 *     double positionX = 0;
 *     double positionY = 0;
 *     double time = 0;
 *     int sequenceNumber = 0;
 * }
 * </pre>
 */
class PlatooningBeacon : public ::omnetpp::cPacket
{
  protected:
    int vehicleId;
    int relayerId;
    double acceleration;
    double speed;
    double positionX;
    double positionY;
    double time;
    int sequenceNumber;

  private:
    void copy(const PlatooningBeacon& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PlatooningBeacon&);

  public:
    PlatooningBeacon(const char *name=nullptr, int kind=0);
    PlatooningBeacon(const PlatooningBeacon& other);
    virtual ~PlatooningBeacon();
    PlatooningBeacon& operator=(const PlatooningBeacon& other);
    virtual PlatooningBeacon *dup() const {return new PlatooningBeacon(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getVehicleId() const;
    virtual void setVehicleId(int vehicleId);
    virtual int getRelayerId() const;
    virtual void setRelayerId(int relayerId);
    virtual double getAcceleration() const;
    virtual void setAcceleration(double acceleration);
    virtual double getSpeed() const;
    virtual void setSpeed(double speed);
    virtual double getPositionX() const;
    virtual void setPositionX(double positionX);
    virtual double getPositionY() const;
    virtual void setPositionY(double positionY);
    virtual double getTime() const;
    virtual void setTime(double time);
    virtual int getSequenceNumber() const;
    virtual void setSequenceNumber(int sequenceNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PlatooningBeacon& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PlatooningBeacon& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PLATOONINGBEACON_M_H

