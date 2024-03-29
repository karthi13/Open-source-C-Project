//
// Copyright (c) 2012-2016 Michele Segata <segata@ccs-labs.org>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "veins/modules/application/platooning/apps/SimplePlatooningApp.h"

#include "veins/modules/messages/WaveShortMessage_m.h"
#include "veins/base/messages/MacPkt_m.h"
#include "veins/modules/mac/ieee80211p/Mac1609_4.h"

#include "veins/modules/application/platooning/protocols/BaseProtocol.h"

Define_Module(SimplePlatooningApp);

void SimplePlatooningApp::initialize(int stage) {
	BaseApp::initialize(stage);
}

void SimplePlatooningApp::finish() {
	BaseApp::finish();
}

void SimplePlatooningApp::onData(WaveShortMessage *wsm) {
}

void SimplePlatooningApp::handleSelfMsg(cMessage *msg) {
	BaseApp::handleSelfMsg(msg);
}

void SimplePlatooningApp::onBeacon(WaveShortMessage* wsm) {
}
