/*
 * PhyLayer.cc
 *
 *  Created on: 11.02.2009
 *      Author: karl
 */

#include "PhyLayer.h"

#include "./Decider80211.h"
#include "Decider802154Narrow.h"
#include "SimplePathlossModel.h"
#include "BreakpointPathlossModel.h"
#include "LogNormalShadowing.h"
#include "SNRThresholdDecider.h"
#include "JakesFading.h"
#include "PERModel.h"
#include "BaseConnectionManager.h"
#include "SimpleObstacleShadowing.h"

Define_Module(PhyLayer);

AnalogueModel* PhyLayer::getAnalogueModelFromName(const std::string& name, ParameterMap& params) const {
    std::string sParamName("");
    std::string sCcParamName("");
    double      dDefault = 0.0;

    sCcParamName = sParamName = "carrierFrequency"; dDefault = 2.412e+9;
    if (params.count(sParamName.c_str()) == 0) {
        if (cc->hasPar(sCcParamName.c_str())) {
            params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(cc->par(sCcParamName.c_str()).doubleValue());
        }
        else {
            params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(dDefault);
        }
    }
    else if(cc->hasPar(sCcParamName.c_str()) && params[sParamName.c_str()].doubleValue() < cc->par(sCcParamName.c_str()).doubleValue()) {
        // throw error
        opp_error("PhyLayer::getAnalogueModelFromName(): %s can't be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly", sParamName.c_str() );
    }

    sCcParamName = sParamName = "alpha"; dDefault = 3.5;
    if (params.count(sParamName.c_str()) == 0) {
        if (cc->hasPar(sCcParamName.c_str())) {
            params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(cc->par(sCcParamName.c_str()).doubleValue());
        }
        else {
            params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(dDefault);
        }
    }
    else if(cc->hasPar(sCcParamName.c_str()) && params[sParamName.c_str()].doubleValue() < cc->par(sCcParamName.c_str()).doubleValue()) {
        // throw error
        opp_error("PhyLayer::getAnalogueModelFromName(): %s can't be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly", sParamName.c_str() );
    }

    sCcParamName = "alpha"; sParamName = "alpha1";
    if (params.count(sParamName.c_str()) == 0) {
        if (cc->hasPar(sCcParamName.c_str())) {
            params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(cc->par(sCcParamName.c_str()).doubleValue());
        }
    }
    else if(cc->hasPar(sCcParamName.c_str()) && params[sParamName.c_str()].doubleValue() < cc->par(sCcParamName.c_str()).doubleValue()) {
        // throw error
        opp_error("PhyLayer::getAnalogueModelFromName(): %s can't be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly", sParamName.c_str() );
    }
    sCcParamName = "alpha"; sParamName = "alpha2";
    if (params.count(sParamName.c_str()) == 0) {
        if (cc->hasPar(sCcParamName.c_str())) {
            params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(cc->par(sCcParamName.c_str()).doubleValue());
        }
    }
    else if(cc->hasPar(sCcParamName.c_str()) && params[sParamName.c_str()].doubleValue() < cc->par(sCcParamName.c_str()).doubleValue()) {
        // throw error
        opp_error("PhyLayer::getAnalogueModelFromName(): %s can't be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly", sParamName.c_str() );
    }

    sParamName = "useTorus";
    params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setBoolValue(world->useTorus());
    sParamName = "PgsX";
    params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(world->getPgs()->x);
    sParamName = "PgsY";
    params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(world->getPgs()->y);
    sParamName = "PgsZ";
    params[sParamName.c_str()] = ParameterMap::mapped_type(sParamName.c_str()).setDoubleValue(world->getPgs()->z);

	if (name == "SimplePathlossModel") {
		return createAnalogueModel<SimplePathlossModel>(params);
	}
	if (name == "LogNormalShadowing") {
		return createAnalogueModel<LogNormalShadowing>(params);
	}
	if (name == "JakesFading") {
		return createAnalogueModel<JakesFading>(params);
	}
	if(name == "BreakpointPathlossModel") {
		return createAnalogueModel<BreakpointPathlossModel>(params);
	}
	if(name == "PERModel") {
		return createAnalogueModel<PERModel>(params);
	}
    if (name == "SimpleObstacleShadowing")
    {
        return initializeSimpleObstacleShadowing(params);
    }
	return BasePhyLayer::getAnalogueModelFromName(name, params);
}

Decider* PhyLayer::getDeciderFromName(const std::string& name, ParameterMap& params) {
    params["recordStats"] = cMsgPar("recordStats").setBoolValue(recordStats);

	if(name == "Decider80211") {
		protocolId = IEEE_80211;
		return createDecider<Decider80211>(params);
	}
	if(name == "SNRThresholdDecider"){
		protocolId = GENERIC;
		return createDecider<SNRThresholdDecider>(params);
	}
	if(name == "Decider802154Narrow") {
		protocolId = IEEE_802154_NARROW;
		return createDecider<Decider802154Narrow>(params);
	}

	return BasePhyLayer::getDeciderFromName(name, params);
}


AnalogueModel* PhyLayer::initializeSimpleObstacleShadowing(ParameterMap& params) const{

    // init with default value
    double carrierFrequency = 2.412e+9;
    bool useTorus = world->useTorus();
    const Coord& playgroundSize = *(world->getPgs());

    ParameterMap::iterator it;

    // get carrierFrequency from config
    it = params.find("carrierFrequency");

    if ( it != params.end() ) // parameter carrierFrequency has been specified in config.xml
    {
        // set carrierFrequency
        carrierFrequency = it->second.doubleValue();
        coreEV << "initializeSimpleObstacleShadowing(): carrierFrequency set from config.xml to " << carrierFrequency << endl;

        // check whether carrierFrequency is not smaller than specified in ConnectionManager
        if(cc->hasPar("carrierFrequency") && carrierFrequency < cc->par("carrierFrequency").doubleValue())
        {
            // throw error
            opp_error("initializeSimpleObstacleShadowing(): carrierFrequency can't be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly");
        }
    }
    else // carrierFrequency has not been specified in config.xml
    {
        if (cc->hasPar("carrierFrequency")) // parameter carrierFrequency has been specified in ConnectionManager
        {
            // set carrierFrequency according to ConnectionManager
            carrierFrequency = cc->par("carrierFrequency").doubleValue();
            coreEV << "createPathLossModel(): carrierFrequency set from ConnectionManager to " << carrierFrequency << endl;
        }
        else // carrierFrequency has not been specified in ConnectionManager
        {
            // keep carrierFrequency at default value
            coreEV << "createPathLossModel(): carrierFrequency set from default value to " << carrierFrequency << endl;
        }
    }

    ObstacleControl* obstacleControlP = ObstacleControlAccess().getIfExists();
    if (!obstacleControlP) opp_error("initializeSimpleObstacleShadowing(): cannot find ObstacleControl module");
    return new SimpleObstacleShadowing(*obstacleControlP, carrierFrequency, useTorus, playgroundSize, coreDebug);
}
