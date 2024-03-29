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

#include "veins/modules/application/platooning/scenarios/SinusoidalScenario.h"

Define_Module(SinusoidalScenario);

void SinusoidalScenario::initialize(int stage) {

	BaseScenario::initialize(stage);



	if (stage == 1) {
		//get the oscillation frequency of the leader as parameter
		leaderOscillationFrequency = par("leaderOscillationFrequency").doubleValue();
		//oscillation amplitude
		oscillationAmplitude = par("oscillationAmplitude").doubleValue() / 3.6;
		//average speed
		leaderSpeed = par("leaderSpeed").doubleValue() / 3.6;
		//start oscillation time
		startOscillating = SimTime(par("startOscillating").doubleValue());

		if (positionHelper->getId() < positionHelper->getLanesCount()) {
			//setup oscillation message, only if i'm part of the first leaders
			changeSpeed = new cMessage("changeSpeed");
			if (simTime() > startOscillating) {
				startOscillating = simTime();
				scheduleAt(simTime(), changeSpeed);
			}
			else {
				scheduleAt(startOscillating, changeSpeed);
			}
			//set base cruising speed
			traciVehicle->setCruiseControlDesiredSpeed(leaderSpeed);
		}
		else {
			//let the follower set a higher desired speed to stay connected
			//to the leader when it is accelerating
			traciVehicle->setCruiseControlDesiredSpeed(leaderSpeed + 2 * oscillationAmplitude);
		}
		measure = new cMessage("measure");
		scheduleAt(SimTime(3), measure);

	}

}

void SinusoidalScenario::finish() {
	cancelAndDelete(changeSpeed);
	changeSpeed = 0;
	BaseScenario::finish();
}

void SinusoidalScenario::handleSelfMsg(cMessage *msg) {
	BaseScenario::handleSelfMsg(msg);
	if (msg == changeSpeed) {
		traciVehicle->setCruiseControlDesiredSpeed(
		    leaderSpeed +
		    oscillationAmplitude *
		    sin(2 * M_PI * (simTime() - startOscillating).dbl() * leaderOscillationFrequency)
		);
		scheduleAt(simTime() + SimTime(0.1), changeSpeed);
	}
	else if(msg == measure){
	    int veh_ID = positionHelper->getId();

//	    std::string ex_ID = positionHelper->getExternalId();
//	    std::string ex_ID = posHelper->getStringIDOfVehicle(veh_ID);

	    std::string dummy = positionHelper->vehicleTypeNames;
	    std::vector<std::string> dummy_vec = positionHelper->vehIDInString;
	    std::string type_veh = dummy_vec.at(veh_ID);
	    double w = traciVehicle->getVehicleWidth(type_veh);
	    double h = traciVehicle->getVehicleHeight(type_veh);

	    scheduleAt(simTime() + SimTime(1), measure);
	}
}








































