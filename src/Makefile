#
# OMNeT++/OMNEST Makefile for libmixim
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -o mixim -O out -DWITH_MIXIM_EXAMPLES -DMIXIM_INET
#

# Name of target to be created (-o option)
TARGET = libmixim$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -Ibase \
    -Ibase/connectionManager \
    -Ibase/messages \
    -Ibase/modules \
    -Ibase/phyLayer \
    -Ibase/utils \
    -Iinet_stub \
    -Iinet_stub/base \
    -Iinet_stub/linklayer \
    -Iinet_stub/linklayer/contract \
    -Iinet_stub/mobility \
    -Iinet_stub/mobility/models \
    -Iinet_stub/networklayer \
    -Iinet_stub/networklayer/common \
    -Iinet_stub/util \
    -Imodules \
    -Imodules/analogueModel \
    -Imodules/application \
    -Imodules/connectionManager \
    -Imodules/mac \
    -Imodules/messages \
    -Imodules/netw \
    -Imodules/nic \
    -Imodules/node \
    -Imodules/obstacle \
    -Imodules/phy \
    -Imodules/power \
    -Imodules/power/battery \
    -Imodules/transport \
    -Imodules/utility \
    -Imodules/world \
    -Imodules/world/annotations

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/base/connectionManager/BaseConnectionManager.o \
    $O/base/connectionManager/ConnectionManager.o \
    $O/base/connectionManager/ConnectionManagerAccess.o \
    $O/base/connectionManager/NicEntryDebug.o \
    $O/base/connectionManager/NicEntryDirect.o \
    $O/base/modules/BaseApplLayer.o \
    $O/base/modules/BaseArp.o \
    $O/base/modules/BaseBattery.o \
    $O/base/modules/BaseLayer.o \
    $O/base/modules/BaseMacLayer.o \
    $O/base/modules/BaseModule.o \
    $O/base/modules/BaseNetwLayer.o \
    $O/base/modules/BaseWorldUtility.o \
    $O/base/modules/MiximBatteryAccess.o \
    $O/base/modules/TestApplLayer.o \
    $O/base/phyLayer/BaseDecider.o \
    $O/base/phyLayer/BasePhyLayer.o \
    $O/base/phyLayer/ChannelInfo.o \
    $O/base/phyLayer/ChannelState.o \
    $O/base/phyLayer/Decider.o \
    $O/base/phyLayer/MappingBase.o \
    $O/base/phyLayer/MappingUtils.o \
    $O/base/phyLayer/PhyUtils.o \
    $O/base/phyLayer/Signal.o \
    $O/base/utils/NetwToMacControlInfo.o \
    $O/base/utils/SimpleAddress.o \
    $O/base/utils/winsupport.o \
    $O/inet_stub/base/BasicModule.o \
    $O/inet_stub/base/Coord.o \
    $O/inet_stub/base/ModuleAccess.o \
    $O/inet_stub/base/NotificationBoard.o \
    $O/inet_stub/base/NotifierConsts.o \
    $O/inet_stub/base/Triangulation.o \
    $O/inet_stub/linklayer/contract/MACAddress.o \
    $O/inet_stub/mobility/models/ANSimMobility.o \
    $O/inet_stub/mobility/models/BonnMotionFileCache.o \
    $O/inet_stub/mobility/models/BonnMotionMobility.o \
    $O/inet_stub/mobility/models/ChiangMobility.o \
    $O/inet_stub/mobility/models/CircleMobility.o \
    $O/inet_stub/mobility/models/ConstSpeedMobility.o \
    $O/inet_stub/mobility/models/GaussMarkovMobility.o \
    $O/inet_stub/mobility/models/LinearMobility.o \
    $O/inet_stub/mobility/models/LinearNodeDistributionMobility.o \
    $O/inet_stub/mobility/models/LineSegmentsMobilityBase.o \
    $O/inet_stub/mobility/models/MassMobility.o \
    $O/inet_stub/mobility/models/MoBANCoordinator.o \
    $O/inet_stub/mobility/models/MoBANLocal.o \
    $O/inet_stub/mobility/models/MobilityAccess.o \
    $O/inet_stub/mobility/models/MobilityBase.o \
    $O/inet_stub/mobility/models/MovingMobilityBase.o \
    $O/inet_stub/mobility/models/Ns2MotionMobility.o \
    $O/inet_stub/mobility/models/Posture.o \
    $O/inet_stub/mobility/models/PostureTransition.o \
    $O/inet_stub/mobility/models/RandomWPMobility.o \
    $O/inet_stub/mobility/models/RectangleMobility.o \
    $O/inet_stub/mobility/models/StaticGridMobility.o \
    $O/inet_stub/mobility/models/StationaryMobility.o \
    $O/inet_stub/mobility/models/TraCIMobility.o \
    $O/inet_stub/mobility/models/TractorMobility.o \
    $O/inet_stub/mobility/models/TurtleMobility.o \
    $O/inet_stub/networklayer/common/InterfaceEntry.o \
    $O/inet_stub/networklayer/common/InterfaceTable.o \
    $O/modules/analogueModel/BreakpointPathlossModel.o \
    $O/modules/analogueModel/JakesFading.o \
    $O/modules/analogueModel/LogNormalShadowing.o \
    $O/modules/analogueModel/PERModel.o \
    $O/modules/analogueModel/SimpleObstacleShadowing.o \
    $O/modules/analogueModel/SimplePathlossModel.o \
    $O/modules/analogueModel/UWBIRIEEE802154APathlossModel.o \
    $O/modules/analogueModel/UWBIRStochasticPathlossModel.o \
    $O/modules/application/BurstApplLayer.o \
    $O/modules/application/BurstApplLayerBattery.o \
    $O/modules/application/SensorApplLayer.o \
    $O/modules/application/TestApplication.o \
    $O/modules/application/TrafficGen.o \
    $O/modules/connectionManager/UnitDisk.o \
    $O/modules/mac/AlohaMacLayer.o \
    $O/modules/mac/BMacLayer.o \
    $O/modules/mac/csma.o \
    $O/modules/mac/CSMA802154.o \
    $O/modules/mac/CSMAMacLayer.o \
    $O/modules/mac/LMacLayer.o \
    $O/modules/mac/Mac80211.o \
    $O/modules/mac/Mac80211MultiChannel.o \
    $O/modules/mac/UWBIRMac.o \
    $O/modules/messages/AggrPkt.o \
    $O/modules/messages/UWBIRMacPkt.o \
    $O/modules/netw/AdaptiveProbabilisticBroadcast.o \
    $O/modules/netw/ArpHost.o \
    $O/modules/netw/DummyRoute.o \
    $O/modules/netw/Flood.o \
    $O/modules/netw/ProbabilisticBroadcast.o \
    $O/modules/netw/WiseRoute.o \
    $O/modules/obstacle/Obstacle.o \
    $O/modules/obstacle/ObstacleControl.o \
    $O/modules/phy/Decider80211.o \
    $O/modules/phy/Decider80211Battery.o \
    $O/modules/phy/Decider80211MultiChannel.o \
    $O/modules/phy/Decider802154Narrow.o \
    $O/modules/phy/DeciderUWBIRED.o \
    $O/modules/phy/DeciderUWBIREDSync.o \
    $O/modules/phy/DeciderUWBIREDSyncOnAddress.o \
    $O/modules/phy/PhyLayer.o \
    $O/modules/phy/PhyLayerBattery.o \
    $O/modules/phy/PhyLayerUWBIR.o \
    $O/modules/phy/SNRThresholdDecider.o \
    $O/modules/power/battery/BatteryStats.o \
    $O/modules/power/battery/SimpleBattery.o \
    $O/modules/transport/Aggregation.o \
    $O/modules/utility/IEEE802154A.o \
    $O/modules/utility/phyPER.o \
    $O/modules/utility/SimTracer.o \
    $O/modules/world/annotations/AnnotationDummy.o \
    $O/modules/world/annotations/AnnotationManager.o \
    $O/base/messages/ApplPkt_m.o \
    $O/base/messages/BorderMsg_m.o \
    $O/base/messages/ChannelSenseRequest_m.o \
    $O/base/messages/MacPkt_m.o \
    $O/base/messages/MiximAirFrame_m.o \
    $O/base/messages/NetwPkt_m.o \
    $O/inet_stub/linklayer/contract/Ieee802Ctrl_m.o \
    $O/modules/messages/AggrPkt_m.o \
    $O/modules/messages/AirFrameUWBIR_m.o \
    $O/modules/messages/DummyRoutePkt_m.o \
    $O/modules/messages/LMacPkt_m.o \
    $O/modules/messages/Mac80211Pkt_m.o \
    $O/modules/messages/ProbabilisticBroadcastPkt_m.o \
    $O/modules/messages/UWBIRMacPkt_m.o \
    $O/modules/messages/WiseRoutePkt_m.o

# Message files
MSGFILES = \
    base/messages/ApplPkt.msg \
    base/messages/BorderMsg.msg \
    base/messages/ChannelSenseRequest.msg \
    base/messages/MacPkt.msg \
    base/messages/MiximAirFrame.msg \
    base/messages/NetwPkt.msg \
    inet_stub/linklayer/contract/Ieee802Ctrl.msg \
    modules/messages/AggrPkt.msg \
    modules/messages/AirFrameUWBIR.msg \
    modules/messages/DummyRoutePkt.msg \
    modules/messages/LMacPkt.msg \
    modules/messages/Mac80211Pkt.msg \
    modules/messages/ProbabilisticBroadcastPkt.msg \
    modules/messages/UWBIRMacPkt.msg \
    modules/messages/WiseRoutePkt.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DWITH_MIXIM_EXAMPLES -DMIXIM_INET $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)echo >.tmp$$$$ $(OBJS) $(EXTRA_OBJS) && $(AR) .tmplib$$$$ @.tmp$$$$ && $(SHLIB_LD) -o $O/$(TARGET) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) .tmplib$$$$ $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS) && rm .tmp$$$$ && rm .tmplib$$$$
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f mixim mixim.exe libmixim.so libmixim.a libmixim.dll libmixim.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f base/*_m.cc base/*_m.h
	$(Q)-rm -f base/connectionManager/*_m.cc base/connectionManager/*_m.h
	$(Q)-rm -f base/messages/*_m.cc base/messages/*_m.h
	$(Q)-rm -f base/modules/*_m.cc base/modules/*_m.h
	$(Q)-rm -f base/phyLayer/*_m.cc base/phyLayer/*_m.h
	$(Q)-rm -f base/utils/*_m.cc base/utils/*_m.h
	$(Q)-rm -f inet_stub/*_m.cc inet_stub/*_m.h
	$(Q)-rm -f inet_stub/base/*_m.cc inet_stub/base/*_m.h
	$(Q)-rm -f inet_stub/linklayer/*_m.cc inet_stub/linklayer/*_m.h
	$(Q)-rm -f inet_stub/linklayer/contract/*_m.cc inet_stub/linklayer/contract/*_m.h
	$(Q)-rm -f inet_stub/mobility/*_m.cc inet_stub/mobility/*_m.h
	$(Q)-rm -f inet_stub/mobility/models/*_m.cc inet_stub/mobility/models/*_m.h
	$(Q)-rm -f inet_stub/networklayer/*_m.cc inet_stub/networklayer/*_m.h
	$(Q)-rm -f inet_stub/networklayer/common/*_m.cc inet_stub/networklayer/common/*_m.h
	$(Q)-rm -f inet_stub/util/*_m.cc inet_stub/util/*_m.h
	$(Q)-rm -f modules/*_m.cc modules/*_m.h
	$(Q)-rm -f modules/analogueModel/*_m.cc modules/analogueModel/*_m.h
	$(Q)-rm -f modules/application/*_m.cc modules/application/*_m.h
	$(Q)-rm -f modules/connectionManager/*_m.cc modules/connectionManager/*_m.h
	$(Q)-rm -f modules/mac/*_m.cc modules/mac/*_m.h
	$(Q)-rm -f modules/messages/*_m.cc modules/messages/*_m.h
	$(Q)-rm -f modules/netw/*_m.cc modules/netw/*_m.h
	$(Q)-rm -f modules/nic/*_m.cc modules/nic/*_m.h
	$(Q)-rm -f modules/node/*_m.cc modules/node/*_m.h
	$(Q)-rm -f modules/obstacle/*_m.cc modules/obstacle/*_m.h
	$(Q)-rm -f modules/phy/*_m.cc modules/phy/*_m.h
	$(Q)-rm -f modules/power/*_m.cc modules/power/*_m.h
	$(Q)-rm -f modules/power/battery/*_m.cc modules/power/battery/*_m.h
	$(Q)-rm -f modules/transport/*_m.cc modules/transport/*_m.h
	$(Q)-rm -f modules/utility/*_m.cc modules/utility/*_m.h
	$(Q)-rm -f modules/world/*_m.cc modules/world/*_m.h
	$(Q)-rm -f modules/world/annotations/*_m.cc modules/world/annotations/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc base/*.cc base/connectionManager/*.cc base/messages/*.cc base/modules/*.cc base/phyLayer/*.cc base/utils/*.cc inet_stub/*.cc inet_stub/base/*.cc inet_stub/linklayer/*.cc inet_stub/linklayer/contract/*.cc inet_stub/mobility/*.cc inet_stub/mobility/models/*.cc inet_stub/networklayer/*.cc inet_stub/networklayer/common/*.cc inet_stub/util/*.cc modules/*.cc modules/analogueModel/*.cc modules/application/*.cc modules/connectionManager/*.cc modules/mac/*.cc modules/messages/*.cc modules/netw/*.cc modules/nic/*.cc modules/node/*.cc modules/obstacle/*.cc modules/phy/*.cc modules/power/*.cc modules/power/battery/*.cc modules/transport/*.cc modules/utility/*.cc modules/world/*.cc modules/world/annotations/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/base/connectionManager/BaseConnectionManager.o: base/connectionManager/BaseConnectionManager.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/connectionManager/NicEntryDebug.h \
	base/connectionManager/NicEntryDirect.h \
	base/modules/BaseWorldUtility.h \
	base/utils/FindModule.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/connectionManager/ConnectionManager.o: base/connectionManager/ConnectionManager.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/modules/BaseWorldUtility.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/connectionManager/ConnectionManagerAccess.o: base/connectionManager/ConnectionManagerAccess.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ConnectionManagerAccess.h \
	base/connectionManager/NicEntry.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/connectionManager/NicEntryDebug.o: base/connectionManager/NicEntryDebug.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/connectionManager/NicEntry.h \
	base/connectionManager/NicEntryDebug.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/connectionManager/NicEntryDirect.o: base/connectionManager/NicEntryDirect.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/connectionManager/NicEntry.h \
	base/connectionManager/NicEntryDirect.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/messages/ApplPkt_m.o: base/messages/ApplPkt_m.cc \
	base/messages/ApplPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/messages/BorderMsg_m.o: base/messages/BorderMsg_m.cc \
	base/messages/BorderMsg_m.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/messages/ChannelSenseRequest_m.o: base/messages/ChannelSenseRequest_m.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/phyLayer/ChannelState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/messages/MacPkt_m.o: base/messages/MacPkt_m.cc \
	base/messages/MacPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/messages/MiximAirFrame_m.o: base/messages/MiximAirFrame_m.cc \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/messages/NetwPkt_m.o: base/messages/NetwPkt_m.cc \
	base/messages/NetwPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/modules/BaseApplLayer.o: base/modules/BaseApplLayer.cc \
	base/modules/BaseApplLayer.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/modules/BaseArp.o: base/modules/BaseArp.cc \
	base/modules/AddressingInterface.h \
	base/modules/ArpInterface.h \
	base/modules/BaseArp.h \
	base/modules/BaseModule.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/modules/BaseBattery.o: base/modules/BaseBattery.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseLayer.o: base/modules/BaseLayer.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseMacLayer.o: base/modules/BaseMacLayer.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/messages/MacPkt_m.h \
	base/modules/AddressingInterface.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MacToNetwControlInfo.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwToMacControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/networklayer/common/IInterfaceTable.h \
	inet_stub/networklayer/common/InterfaceEntry.h \
	inet_stub/networklayer/common/InterfaceTableAccess.h \
	inet_stub/networklayer/common/InterfaceToken.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/modules/BaseModule.o: base/modules/BaseModule.cc \
	base/modules/BaseModule.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseNetwLayer.o: base/modules/BaseNetwLayer.cc \
	base/messages/NetwPkt_m.h \
	base/modules/AddressingInterface.h \
	base/modules/ArpInterface.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MappingBase.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/NetwToMacControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/modules/BaseWorldUtility.o: base/modules/BaseWorldUtility.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/modules/BaseWorldUtility.h \
	base/utils/FindModule.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/modules/MiximBatteryAccess.o: base/modules/MiximBatteryAccess.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/modules/TestApplLayer.o: base/modules/TestApplLayer.cc \
	base/messages/ApplPkt_m.h \
	base/modules/BaseApplLayer.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/modules/TestApplLayer.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/phyLayer/BaseDecider.o: base/phyLayer/BaseDecider.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h
$O/base/phyLayer/BasePhyLayer.o: base/phyLayer/BasePhyLayer.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ConnectionManagerAccess.h \
	base/connectionManager/NicEntry.h \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/phyLayer/ChannelInfo.o: base/phyLayer/ChannelInfo.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/ChannelState.o: base/phyLayer/ChannelState.cc \
	base/phyLayer/ChannelState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/Decider.o: base/phyLayer/Decider.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/MappingBase.o: base/phyLayer/MappingBase.cc \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MappingBase.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/MappingUtils.o: base/phyLayer/MappingUtils.cc \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/PhyUtils.o: base/phyLayer/PhyUtils.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/base/phyLayer/Signal.o: base/phyLayer/Signal.cc \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/utils/NetwToMacControlInfo.o: base/utils/NetwToMacControlInfo.cc \
	base/utils/MiXiMDefs.h \
	base/utils/NetwToMacControlInfo.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/Ieee802Ctrl_m.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/utils/SimpleAddress.o: base/utils/SimpleAddress.cc \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/base/utils/winsupport.o: base/utils/winsupport.cc \
	base/utils/winsupport.h
$O/inet_stub/base/BasicModule.o: inet_stub/base/BasicModule.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h
$O/inet_stub/base/Coord.o: inet_stub/base/Coord.cc \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/base/ModuleAccess.o: inet_stub/base/ModuleAccess.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h
$O/inet_stub/base/NotificationBoard.o: inet_stub/base/NotificationBoard.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h
$O/inet_stub/base/NotifierConsts.o: inet_stub/base/NotifierConsts.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/base/NotifierConsts.h
$O/inet_stub/base/Triangulation.o: inet_stub/base/Triangulation.cc \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/Triangulation.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/linklayer/contract/Ieee802Ctrl_m.o: inet_stub/linklayer/contract/Ieee802Ctrl_m.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/Ieee802Ctrl_m.h \
	inet_stub/linklayer/contract/MACAddress.h
$O/inet_stub/linklayer/contract/MACAddress.o: inet_stub/linklayer/contract/MACAddress.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/networklayer/common/InterfaceToken.h
$O/inet_stub/mobility/models/ANSimMobility.o: inet_stub/mobility/models/ANSimMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/ANSimMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/BonnMotionFileCache.o: inet_stub/mobility/models/BonnMotionFileCache.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/mobility/models/BonnMotionFileCache.h
$O/inet_stub/mobility/models/BonnMotionMobility.o: inet_stub/mobility/models/BonnMotionMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/BonnMotionFileCache.h \
	inet_stub/mobility/models/BonnMotionMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/ChiangMobility.o: inet_stub/mobility/models/ChiangMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/ChiangMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/CircleMobility.o: inet_stub/mobility/models/CircleMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/CircleMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/ConstSpeedMobility.o: inet_stub/mobility/models/ConstSpeedMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/ConstSpeedMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/GaussMarkovMobility.o: inet_stub/mobility/models/GaussMarkovMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/GaussMarkovMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/LineSegmentsMobilityBase.o: inet_stub/mobility/models/LineSegmentsMobilityBase.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/LinearMobility.o: inet_stub/mobility/models/LinearMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LinearMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/LinearNodeDistributionMobility.o: inet_stub/mobility/models/LinearNodeDistributionMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LinearNodeDistributionMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/StationaryMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/MassMobility.o: inet_stub/mobility/models/MassMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MassMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/MoBANCoordinator.o: inet_stub/mobility/models/MoBANCoordinator.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MoBANCoordinator.h \
	inet_stub/mobility/models/MoBANLocal.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/mobility/models/Posture.h \
	inet_stub/mobility/models/PostureTransition.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/MoBANLocal.o: inet_stub/mobility/models/MoBANLocal.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MoBANCoordinator.h \
	inet_stub/mobility/models/MoBANLocal.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/mobility/models/Posture.h \
	inet_stub/mobility/models/PostureTransition.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/MobilityAccess.o: inet_stub/mobility/models/MobilityAccess.cc \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/MobilityBase.o: inet_stub/mobility/models/MobilityBase.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/MovingMobilityBase.o: inet_stub/mobility/models/MovingMobilityBase.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/Ns2MotionMobility.o: inet_stub/mobility/models/Ns2MotionMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/mobility/models/Ns2MotionMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/Posture.o: inet_stub/mobility/models/Posture.cc \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/mobility/models/Posture.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/PostureTransition.o: inet_stub/mobility/models/PostureTransition.cc \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/mobility/models/PostureTransition.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/RandomWPMobility.o: inet_stub/mobility/models/RandomWPMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/mobility/models/RandomWPMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/RectangleMobility.o: inet_stub/mobility/models/RectangleMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/mobility/models/RectangleMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/StaticGridMobility.o: inet_stub/mobility/models/StaticGridMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/StaticGridMobility.h \
	inet_stub/mobility/models/StationaryMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/StationaryMobility.o: inet_stub/mobility/models/StationaryMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/StationaryMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/TraCIMobility.o: inet_stub/mobility/models/TraCIMobility.cc
$O/inet_stub/mobility/models/TractorMobility.o: inet_stub/mobility/models/TractorMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/mobility/models/TractorMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/mobility/models/TurtleMobility.o: inet_stub/mobility/models/TurtleMobility.cc \
	inet_stub/base/BasicModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/LineSegmentsMobilityBase.h \
	inet_stub/mobility/models/MobilityBase.h \
	inet_stub/mobility/models/MovingMobilityBase.h \
	inet_stub/mobility/models/TurtleMobility.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/inet_stub/networklayer/common/InterfaceEntry.o: inet_stub/networklayer/common/InterfaceEntry.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/networklayer/common/IInterfaceTable.h \
	inet_stub/networklayer/common/InterfaceEntry.h \
	inet_stub/networklayer/common/InterfaceToken.h
$O/inet_stub/networklayer/common/InterfaceTable.o: inet_stub/networklayer/common/InterfaceTable.cc \
	inet_stub/base/INETDefs.h \
	inet_stub/base/INotifiable.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/base/NotificationBoard.h \
	inet_stub/base/NotifierConsts.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/networklayer/common/IInterfaceTable.h \
	inet_stub/networklayer/common/InterfaceEntry.h \
	inet_stub/networklayer/common/InterfaceTable.h \
	inet_stub/networklayer/common/InterfaceToken.h
$O/modules/analogueModel/BreakpointPathlossModel.o: modules/analogueModel/BreakpointPathlossModel.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/BreakpointPathlossModel.h
$O/modules/analogueModel/JakesFading.o: modules/analogueModel/JakesFading.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/JakesFading.h
$O/modules/analogueModel/LogNormalShadowing.o: modules/analogueModel/LogNormalShadowing.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/LogNormalShadowing.h
$O/modules/analogueModel/PERModel.o: modules/analogueModel/PERModel.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/PERModel.h
$O/modules/analogueModel/SimpleObstacleShadowing.o: modules/analogueModel/SimpleObstacleShadowing.cc \
	base/modules/BaseWorldUtility.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/FindModule.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/SimpleObstacleShadowing.h \
	modules/obstacle/Obstacle.h \
	modules/obstacle/ObstacleControl.h \
	modules/world/annotations/AnnotationManager.h
$O/modules/analogueModel/SimplePathlossModel.o: modules/analogueModel/SimplePathlossModel.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseWorldUtility.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/SimplePathlossModel.h
$O/modules/analogueModel/UWBIRIEEE802154APathlossModel.o: modules/analogueModel/UWBIRIEEE802154APathlossModel.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/UWBIRIEEE802154APathlossModel.h \
	modules/utility/IEEE802154A.h \
	modules/utility/SimpleTimeConstMapping.h
$O/modules/analogueModel/UWBIRStochasticPathlossModel.o: modules/analogueModel/UWBIRStochasticPathlossModel.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseWorldUtility.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/UWBIRStochasticPathlossModel.h
$O/modules/application/BurstApplLayer.o: modules/application/BurstApplLayer.cc \
	base/messages/ApplPkt_m.h \
	base/modules/BaseApplLayer.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/modules/TestApplLayer.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/application/BurstApplLayer.h
$O/modules/application/BurstApplLayerBattery.o: modules/application/BurstApplLayerBattery.cc \
	base/messages/ApplPkt_m.h \
	base/modules/BaseApplLayer.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/modules/TestApplLayer.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/application/BurstApplLayer.h \
	modules/application/BurstApplLayerBattery.h
$O/modules/application/SensorApplLayer.o: modules/application/SensorApplLayer.cc \
	base/messages/ApplPkt_m.h \
	base/modules/AddressingInterface.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/application/SensorApplLayer.h \
	modules/utility/Packet.h
$O/modules/application/TestApplication.o: modules/application/TestApplication.cc \
	base/messages/ApplPkt_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MappingBase.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/application/TestApplication.h
$O/modules/application/TrafficGen.o: modules/application/TrafficGen.cc \
	base/messages/ApplPkt_m.h \
	base/modules/BaseApplLayer.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/application/TrafficGen.h \
	modules/utility/Packet.h
$O/modules/connectionManager/UnitDisk.o: modules/connectionManager/UnitDisk.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/connectionManager/UnitDisk.h
$O/modules/mac/AlohaMacLayer.o: modules/mac/AlohaMacLayer.cc \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/mac/AlohaMacLayer.h \
	modules/mac/UWBIRMac.h \
	modules/messages/UWBIRMacPkt.h \
	modules/messages/UWBIRMacPkt_m.h \
	modules/utility/IEEE802154A.h \
	modules/utility/Packet.h
$O/modules/mac/BMacLayer.o: modules/mac/BMacLayer.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/messages/MacPkt_m.h \
	base/modules/AddressingInterface.h \
	base/modules/ArpInterface.h \
	base/modules/BaseArp.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/mac/BMacLayer.h \
	modules/utility/DroppedPacket.h
$O/modules/mac/CSMA802154.o: modules/mac/CSMA802154.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MacPkt_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/utils/HostState.h \
	base/utils/MacToNetwControlInfo.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/mac/CSMA802154.h \
	modules/mac/csma.h \
	modules/phy/Decider802154Narrow.h \
	modules/phy/DeciderResult802154Narrow.h \
	modules/utility/DroppedPacket.h
$O/modules/mac/CSMAMacLayer.o: modules/mac/CSMAMacLayer.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/messages/MacPkt_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h
$O/modules/mac/LMacLayer.o: modules/mac/LMacLayer.cc \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/mac/LMacLayer.h \
	modules/messages/LMacPkt_m.h \
	modules/utility/DroppedPacket.h
$O/modules/mac/Mac80211.o: modules/mac/Mac80211.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/mac/Mac80211.h \
	modules/messages/Mac80211Pkt_m.h \
	modules/phy/Decider80211.h \
	modules/phy/DeciderResult80211.h \
	modules/utility/Consts80211.h
$O/modules/mac/Mac80211MultiChannel.o: modules/mac/Mac80211MultiChannel.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/mac/Mac80211MultiChannel.h
$O/modules/mac/UWBIRMac.o: modules/mac/UWBIRMac.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/mac/UWBIRMac.h \
	modules/messages/UWBIRMacPkt.h \
	modules/messages/UWBIRMacPkt_m.h \
	modules/phy/DeciderResultUWBIR.h \
	modules/phy/MacToUWBIRPhyControlInfo.h \
	modules/utility/IEEE802154A.h \
	modules/utility/Packet.h
$O/modules/mac/csma.o: modules/mac/csma.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ConnectionManagerAccess.h \
	base/connectionManager/NicEntry.h \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/AddressingInterface.h \
	base/modules/ArpInterface.h \
	base/modules/BaseArp.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/mac/csma.h \
	modules/utility/DroppedPacket.h
$O/modules/messages/AggrPkt.o: modules/messages/AggrPkt.cc \
	base/messages/ApplPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/AggrPkt.h \
	modules/messages/AggrPkt_m.h
$O/modules/messages/AggrPkt_m.o: modules/messages/AggrPkt_m.cc \
	base/messages/ApplPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/AggrPkt_m.h
$O/modules/messages/AirFrameUWBIR_m.o: modules/messages/AirFrameUWBIR_m.cc \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	modules/messages/AirFrameUWBIR_m.h \
	modules/utility/IEEE802154A.h
$O/modules/messages/DummyRoutePkt_m.o: modules/messages/DummyRoutePkt_m.cc \
	base/messages/NetwPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/DummyRoutePkt_m.h
$O/modules/messages/LMacPkt_m.o: modules/messages/LMacPkt_m.cc \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/LMacPkt_m.h
$O/modules/messages/Mac80211Pkt_m.o: modules/messages/Mac80211Pkt_m.cc \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/Mac80211Pkt_m.h
$O/modules/messages/ProbabilisticBroadcastPkt_m.o: modules/messages/ProbabilisticBroadcastPkt_m.cc \
	base/messages/NetwPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/ProbabilisticBroadcastPkt_m.h
$O/modules/messages/UWBIRMacPkt.o: modules/messages/UWBIRMacPkt.cc \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/UWBIRMacPkt.h \
	modules/messages/UWBIRMacPkt_m.h
$O/modules/messages/UWBIRMacPkt_m.o: modules/messages/UWBIRMacPkt_m.cc \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMMacPkt.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/UWBIRMacPkt_m.h
$O/modules/messages/WiseRoutePkt_m.o: modules/messages/WiseRoutePkt_m.cc \
	base/messages/NetwPkt_m.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/WiseRoutePkt_m.h
$O/modules/netw/AdaptiveProbabilisticBroadcast.o: modules/netw/AdaptiveProbabilisticBroadcast.cc \
	base/messages/NetwPkt_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/ProbabilisticBroadcastPkt_m.h \
	modules/netw/AdaptiveProbabilisticBroadcast.h \
	modules/netw/ProbabilisticBroadcast.h
$O/modules/netw/ArpHost.o: modules/netw/ArpHost.cc \
	base/modules/AddressingInterface.h \
	base/modules/ArpInterface.h \
	base/modules/BaseModule.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/netw/ArpHost.h
$O/modules/netw/DummyRoute.o: modules/netw/DummyRoute.cc \
	base/messages/NetwPkt_m.h \
	base/modules/ArpInterface.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/DummyRoutePkt_m.h \
	modules/netw/DummyRoute.h
$O/modules/netw/Flood.o: modules/netw/Flood.cc \
	base/messages/NetwPkt_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/netw/Flood.h
$O/modules/netw/ProbabilisticBroadcast.o: modules/netw/ProbabilisticBroadcast.cc \
	base/messages/NetwPkt_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MacToNetwControlInfo.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/ProbabilisticBroadcastPkt_m.h \
	modules/netw/ProbabilisticBroadcast.h \
	modules/utility/ProbBcastNetwControlInfo.h
$O/modules/netw/WiseRoute.o: modules/netw/WiseRoute.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/messages/NetwPkt_m.h \
	base/modules/ArpInterface.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseNetwLayer.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MacToNetwControlInfo.h \
	base/utils/MiXiMDefs.h \
	base/utils/NetwControlInfo.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/messages/WiseRoutePkt_m.h \
	modules/netw/WiseRoute.h \
	modules/utility/Packet.h \
	modules/utility/SimTracer.h
$O/modules/obstacle/Obstacle.o: modules/obstacle/Obstacle.cc \
	base/utils/FindModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/obstacle/Obstacle.h \
	modules/world/annotations/AnnotationManager.h
$O/modules/obstacle/ObstacleControl.o: modules/obstacle/ObstacleControl.cc \
	base/utils/FindModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/obstacle/Obstacle.h \
	modules/obstacle/ObstacleControl.h \
	modules/world/annotations/AnnotationManager.h
$O/modules/phy/Decider80211.o: modules/phy/Decider80211.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiXiMMacPkt.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/Mac80211Pkt_m.h \
	modules/phy/DeciderResult80211.h \
	modules/utility/Consts80211.h
$O/modules/phy/Decider80211Battery.o: modules/phy/Decider80211Battery.cc \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/phy/Decider80211Battery.h
$O/modules/phy/Decider80211MultiChannel.o: modules/phy/Decider80211MultiChannel.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	modules/phy/Decider80211Battery.h \
	modules/phy/Decider80211MultiChannel.h \
	modules/phy/DeciderResult80211.h \
	modules/utility/Consts80211.h
$O/modules/phy/Decider802154Narrow.o: modules/phy/Decider802154Narrow.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiXiMMacPkt.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/phy/Decider802154Narrow.h \
	modules/phy/DeciderResult802154Narrow.h
$O/modules/phy/DeciderUWBIRED.o: modules/phy/DeciderUWBIRED.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/messages/AirFrameUWBIR_m.h \
	modules/phy/DeciderResultUWBIR.h \
	modules/phy/DeciderUWBIRED.h \
	modules/phy/PhyLayer.h \
	modules/phy/PhyLayerBattery.h \
	modules/phy/PhyLayerUWBIR.h \
	modules/phy/RadioUWBIR.h \
	modules/utility/IEEE802154A.h \
	modules/utility/UWBIRPacket.h
$O/modules/phy/DeciderUWBIREDSync.o: modules/phy/DeciderUWBIREDSync.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/phy/DeciderUWBIRED.h \
	modules/phy/DeciderUWBIREDSync.h \
	modules/utility/IEEE802154A.h \
	modules/utility/UWBIRPacket.h
$O/modules/phy/DeciderUWBIREDSyncOnAddress.o: modules/phy/DeciderUWBIREDSyncOnAddress.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiXiMMacPkt.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/phy/DeciderUWBIRED.h \
	modules/phy/DeciderUWBIREDSyncOnAddress.h \
	modules/utility/IEEE802154A.h \
	modules/utility/UWBIRPacket.h
$O/modules/phy/PhyLayer.o: modules/phy/PhyLayer.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ConnectionManagerAccess.h \
	base/connectionManager/NicEntry.h \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/BreakpointPathlossModel.h \
	modules/analogueModel/JakesFading.h \
	modules/analogueModel/LogNormalShadowing.h \
	modules/analogueModel/PERModel.h \
	modules/analogueModel/SimpleObstacleShadowing.h \
	modules/analogueModel/SimplePathlossModel.h \
	modules/obstacle/Obstacle.h \
	modules/obstacle/ObstacleControl.h \
	modules/phy/Decider802154Narrow.h \
	modules/phy/PhyLayer.h \
	modules/phy/SNRThresholdDecider.h \
	modules/world/annotations/AnnotationManager.h
$O/modules/phy/PhyLayerBattery.o: modules/phy/PhyLayerBattery.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/messages/MacPkt_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiXiMMacPkt.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/phy/Decider80211Battery.h \
	modules/phy/Decider80211MultiChannel.h \
	modules/phy/PhyLayer.h \
	modules/phy/PhyLayerBattery.h
$O/modules/phy/PhyLayerUWBIR.o: modules/phy/PhyLayerUWBIR.cc \
	base/connectionManager/ConnectionManagerAccess.h \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/base/ModuleAccess.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/mobility/IMobility.h \
	inet_stub/mobility/models/MobilityAccess.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/analogueModel/UWBIRIEEE802154APathlossModel.h \
	modules/analogueModel/UWBIRStochasticPathlossModel.h \
	modules/messages/AirFrameUWBIR_m.h \
	modules/phy/DeciderUWBIRED.h \
	modules/phy/DeciderUWBIREDSync.h \
	modules/phy/DeciderUWBIREDSyncOnAddress.h \
	modules/phy/MacToUWBIRPhyControlInfo.h \
	modules/phy/PhyLayer.h \
	modules/phy/PhyLayerBattery.h \
	modules/phy/PhyLayerUWBIR.h \
	modules/phy/RadioUWBIR.h \
	modules/utility/IEEE802154A.h \
	modules/utility/SimpleTimeConstMapping.h \
	modules/utility/UWBIRPacket.h
$O/modules/phy/SNRThresholdDecider.o: modules/phy/SNRThresholdDecider.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/messages/MiXiMAirFrame.h \
	base/messages/MiximAirFrame_m.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	modules/phy/SNRThresholdDecider.h
$O/modules/power/battery/BatteryStats.o: modules/power/battery/BatteryStats.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	modules/power/battery/BatteryState.h \
	modules/power/battery/BatteryStats.h \
	modules/power/battery/DeviceEntry.h
$O/modules/power/battery/SimpleBattery.o: modules/power/battery/SimpleBattery.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	modules/power/battery/BatteryState.h \
	modules/power/battery/BatteryStats.h \
	modules/power/battery/DeviceEntry.h \
	modules/power/battery/SimpleBattery.h
$O/modules/transport/Aggregation.o: modules/transport/Aggregation.cc \
	base/messages/ApplPkt_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	modules/messages/AggrPkt.h \
	modules/messages/AggrPkt_m.h \
	modules/transport/Aggregation.h
$O/modules/utility/IEEE802154A.o: modules/utility/IEEE802154A.cc \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	modules/utility/IEEE802154A.h
$O/modules/utility/SimTracer.o: modules/utility/SimTracer.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/MiximBatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/utility/Packet.h \
	modules/utility/SimTracer.h
$O/modules/utility/phyPER.o: modules/utility/phyPER.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/MiximBatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/linklayer/contract/MACAddress.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/phy/DeciderUWBIRED.h \
	modules/utility/IEEE802154A.h \
	modules/utility/Packet.h \
	modules/utility/UWBIRPacket.h \
	modules/utility/phyPER.h
$O/modules/world/annotations/AnnotationDummy.o: modules/world/annotations/AnnotationDummy.cc \
	modules/world/annotations/AnnotationDummy.h
$O/modules/world/annotations/AnnotationManager.o: modules/world/annotations/AnnotationManager.cc \
	base/utils/FindModule.h \
	inet_stub/base/Coord.h \
	inet_stub/base/INETDefs.h \
	inet_stub/util/FWMath.h \
	inet_stub/util/Line2D.h \
	inet_stub/util/Vector2D.h \
	modules/world/annotations/AnnotationManager.h

