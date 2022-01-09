#
# OMNeT++/OMNEST Makefile for miximtests
#
# This file was generated with the command:
#  opp_makemake -f --deep -o miximtests -O out -I../src/inet_stub/mobility/models -I../src/base -I../src/base/utils -I../src -I../src/inet_stub/networklayer/common -I../src/inet_stub/mobility -I../src/inet_stub/util -I../src/base/phyLayer -I../src/base/modules -I../src/inet_stub/base -I../src/base/connectionManager -I../src/inet_stub/linklayer/contract -I../src/base/messages -I../src/modules/analogueModel -I../src/modules/phy -I../src/modules/utility -I../src/modules -I../src/modules/obstacle -I../src/modules/messages -I../src/modules/mac -I../src/modules/power/battery -L../out/$$\(CONFIGNAME\)/src -lmixim -DWITH_MIXIM_EXAMPLES -DMIXIM_INET
#

# Name of target to be created (-o option)
TARGET = miximtests$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../src/inet_stub/mobility/models \
    -I../src/base \
    -I../src/base/utils \
    -I../src \
    -I../src/inet_stub/networklayer/common \
    -I../src/inet_stub/mobility \
    -I../src/inet_stub/util \
    -I../src/base/phyLayer \
    -I../src/base/modules \
    -I../src/inet_stub/base \
    -I../src/base/connectionManager \
    -I../src/inet_stub/linklayer/contract \
    -I../src/base/messages \
    -I../src/modules/analogueModel \
    -I../src/modules/phy \
    -I../src/modules/utility \
    -I../src/modules \
    -I../src/modules/obstacle \
    -I../src/modules/messages \
    -I../src/modules/mac \
    -I../src/modules/power/battery \
    -I. \
    -IbasePhyLayer \
    -IchannelInfo \
    -IconnectionManager \
    -Icoord \
    -Idecider \
    -Imapping \
    -InicTest \
    -Ipower \
    -Ipower/Nic80211Test \
    -Ipower/Nic80211Test/valid \
    -Ipower/Nic80211Test/valid/battery_80211 \
    -Ipower/Nic80211Test/valid/out_10 \
    -Ipower/Nic80211Test/valid/out_50 \
    -Ipower/deviceTest \
    -Ipower/deviceTest/valid \
    -Ipower/deviceTestAccts \
    -Ipower/deviceTestAccts/valid \
    -Ipower/deviceTestAll \
    -Ipower/deviceTestAll/valid \
    -Ipower/deviceTestMulti \
    -Ipower/deviceTestMulti/valid \
    -Ipower/utils \
    -IradioState \
    -ItestUtils

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../out/$(CONFIGNAME)/src  -lmixim
LIBS += -Wl,-rpath,`abspath ../out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = tests
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/basePhyLayer/BasePhyTests.o \
    $O/basePhyLayer/TestMacLayer.o \
    $O/basePhyLayer/TestPhyLayer.o \
    $O/channelInfo/ChannelInfoTest.o \
    $O/connectionManager/CMPhyLayer.o \
    $O/connectionManager/ConnectedBCNodePhyLayer.o \
    $O/connectionManager/ConnectedRNodePhyLayer.o \
    $O/connectionManager/NotConnectedBCNodePhyLayer.o \
    $O/connectionManager/NotConnectedRNodePhyLayer.o \
    $O/connectionManager/TestCM.o \
    $O/coord/CoordTest.o \
    $O/decider/DeciderTest.o \
    $O/mapping/mappingtest.o \
    $O/nicTest/NicTests.o \
    $O/nicTest/TestApp.o \
    $O/power/utils/DeviceDuty.o \
    $O/power/utils/DeviceDutySimple.o \
    $O/power/utils/Subscriber.o \
    $O/radioState/TestPhyUtils.o \
    $O/testUtils/asserts.o \
    $O/testUtils/OmnetTestBase.o \
    $O/testUtils/Testmanager.o \
    $O/testUtils/TestModule.o

# Message files
MSGFILES =

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
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

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
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

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
	$(Q)-rm -f miximtests miximtests.exe libmiximtests.so libmiximtests.a libmiximtests.dll libmiximtests.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f basePhyLayer/*_m.cc basePhyLayer/*_m.h
	$(Q)-rm -f channelInfo/*_m.cc channelInfo/*_m.h
	$(Q)-rm -f connectionManager/*_m.cc connectionManager/*_m.h
	$(Q)-rm -f coord/*_m.cc coord/*_m.h
	$(Q)-rm -f decider/*_m.cc decider/*_m.h
	$(Q)-rm -f mapping/*_m.cc mapping/*_m.h
	$(Q)-rm -f nicTest/*_m.cc nicTest/*_m.h
	$(Q)-rm -f power/*_m.cc power/*_m.h
	$(Q)-rm -f power/Nic80211Test/*_m.cc power/Nic80211Test/*_m.h
	$(Q)-rm -f power/Nic80211Test/valid/*_m.cc power/Nic80211Test/valid/*_m.h
	$(Q)-rm -f power/Nic80211Test/valid/battery_80211/*_m.cc power/Nic80211Test/valid/battery_80211/*_m.h
	$(Q)-rm -f power/Nic80211Test/valid/out_10/*_m.cc power/Nic80211Test/valid/out_10/*_m.h
	$(Q)-rm -f power/Nic80211Test/valid/out_50/*_m.cc power/Nic80211Test/valid/out_50/*_m.h
	$(Q)-rm -f power/deviceTest/*_m.cc power/deviceTest/*_m.h
	$(Q)-rm -f power/deviceTest/valid/*_m.cc power/deviceTest/valid/*_m.h
	$(Q)-rm -f power/deviceTestAccts/*_m.cc power/deviceTestAccts/*_m.h
	$(Q)-rm -f power/deviceTestAccts/valid/*_m.cc power/deviceTestAccts/valid/*_m.h
	$(Q)-rm -f power/deviceTestAll/*_m.cc power/deviceTestAll/*_m.h
	$(Q)-rm -f power/deviceTestAll/valid/*_m.cc power/deviceTestAll/valid/*_m.h
	$(Q)-rm -f power/deviceTestMulti/*_m.cc power/deviceTestMulti/*_m.h
	$(Q)-rm -f power/deviceTestMulti/valid/*_m.cc power/deviceTestMulti/valid/*_m.h
	$(Q)-rm -f power/utils/*_m.cc power/utils/*_m.h
	$(Q)-rm -f radioState/*_m.cc radioState/*_m.h
	$(Q)-rm -f testUtils/*_m.cc testUtils/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc basePhyLayer/*.cc channelInfo/*.cc connectionManager/*.cc coord/*.cc decider/*.cc mapping/*.cc nicTest/*.cc power/*.cc power/Nic80211Test/*.cc power/Nic80211Test/valid/*.cc power/Nic80211Test/valid/battery_80211/*.cc power/Nic80211Test/valid/out_10/*.cc power/Nic80211Test/valid/out_50/*.cc power/deviceTest/*.cc power/deviceTest/valid/*.cc power/deviceTestAccts/*.cc power/deviceTestAccts/valid/*.cc power/deviceTestAll/*.cc power/deviceTestAll/valid/*.cc power/deviceTestMulti/*.cc power/deviceTestMulti/valid/*.cc power/utils/*.cc radioState/*.cc testUtils/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/basePhyLayer/BasePhyTests.o: basePhyLayer/BasePhyTests.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/ChannelSenseRequest_m.h \
	../src/base/messages/MiXiMAirFrame.h \
	../src/base/messages/MiximAirFrame_m.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/BasePhyLayer.h \
	../src/base/phyLayer/ChannelInfo.h \
	../src/base/phyLayer/ChannelState.h \
	../src/base/phyLayer/Decider.h \
	../src/base/phyLayer/DeciderToPhyInterface.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/MacToPhyInterface.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/PhyUtils.h \
	../src/base/phyLayer/Signal_.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	basePhyLayer/BasePhyTests.h \
	basePhyLayer/TestDecider.h \
	basePhyLayer/TestGlobals.h \
	basePhyLayer/TestMacLayer.h \
	basePhyLayer/TestPhyLayer.h \
	testUtils/OmnetTestBase.h \
	testUtils/TestManager.h \
	testUtils/TestModule.h \
	testUtils/asserts.h
$O/basePhyLayer/TestMacLayer.o: basePhyLayer/TestMacLayer.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/ChannelSenseRequest_m.h \
	../src/base/messages/MacPkt_m.h \
	../src/base/messages/MiXiMAirFrame.h \
	../src/base/messages/MiXiMMacPkt.h \
	../src/base/messages/MiximAirFrame_m.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/BasePhyLayer.h \
	../src/base/phyLayer/ChannelInfo.h \
	../src/base/phyLayer/ChannelState.h \
	../src/base/phyLayer/Decider.h \
	../src/base/phyLayer/DeciderToPhyInterface.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/MacToPhyControlInfo.h \
	../src/base/phyLayer/MacToPhyInterface.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/PhyUtils.h \
	../src/base/phyLayer/Signal_.h \
	../src/base/utils/FindModule.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	basePhyLayer/TestDecider.h \
	basePhyLayer/TestGlobals.h \
	basePhyLayer/TestMacLayer.h \
	basePhyLayer/TestPhyLayer.h \
	testUtils/OmnetTestBase.h \
	testUtils/TestManager.h \
	testUtils/TestModule.h \
	testUtils/asserts.h
$O/basePhyLayer/TestPhyLayer.o: basePhyLayer/TestPhyLayer.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/ChannelSenseRequest_m.h \
	../src/base/messages/MiXiMAirFrame.h \
	../src/base/messages/MiximAirFrame_m.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/BasePhyLayer.h \
	../src/base/phyLayer/ChannelInfo.h \
	../src/base/phyLayer/ChannelState.h \
	../src/base/phyLayer/Decider.h \
	../src/base/phyLayer/DeciderToPhyInterface.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/MacToPhyInterface.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/PhyUtils.h \
	../src/base/phyLayer/Signal_.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	basePhyLayer/TestDecider.h \
	basePhyLayer/TestGlobals.h \
	basePhyLayer/TestPhyLayer.h \
	testUtils/OmnetTestBase.h \
	testUtils/TestManager.h \
	testUtils/TestModule.h \
	testUtils/asserts.h
$O/channelInfo/ChannelInfoTest.o: channelInfo/ChannelInfoTest.cc \
	../src/base/messages/MiXiMAirFrame.h \
	../src/base/messages/MiximAirFrame_m.h \
	../src/base/phyLayer/ChannelInfo.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/Signal_.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	testUtils/OmnetTestBase.h \
	testUtils/asserts.h
$O/connectionManager/CMPhyLayer.o: connectionManager/CMPhyLayer.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/MacPkt_m.h \
	../src/base/messages/MiXiMMacPkt.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	connectionManager/CMPhyLayer.h
$O/connectionManager/ConnectedBCNodePhyLayer.o: connectionManager/ConnectedBCNodePhyLayer.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/MacPkt_m.h \
	../src/base/messages/MiXiMMacPkt.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	connectionManager/CMPhyLayer.h \
	connectionManager/ConnectedBCNodePhyLayer.h
$O/connectionManager/ConnectedRNodePhyLayer.o: connectionManager/ConnectedRNodePhyLayer.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/MacPkt_m.h \
	../src/base/messages/MiXiMMacPkt.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	connectionManager/CMPhyLayer.h \
	connectionManager/ConnectedRNodePhyLayer.h
$O/connectionManager/NotConnectedBCNodePhyLayer.o: connectionManager/NotConnectedBCNodePhyLayer.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/MacPkt_m.h \
	../src/base/messages/MiXiMMacPkt.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	connectionManager/CMPhyLayer.h \
	connectionManager/NotConnectedBCNodePhyLayer.h
$O/connectionManager/NotConnectedRNodePhyLayer.o: connectionManager/NotConnectedRNodePhyLayer.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/MacPkt_m.h \
	../src/base/messages/MiXiMMacPkt.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	connectionManager/CMPhyLayer.h \
	connectionManager/NotConnectedRNodePhyLayer.h
$O/connectionManager/TestCM.o: connectionManager/TestCM.cc \
	../src/base/connectionManager/BaseConnectionManager.h \
	../src/base/connectionManager/NicEntry.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	connectionManager/TestCM.h \
	testUtils/asserts.h
$O/coord/CoordTest.o: coord/CoordTest.cc \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	testUtils/OmnetTestBase.h \
	testUtils/asserts.h
$O/decider/DeciderTest.o: decider/DeciderTest.cc \
	../src/base/connectionManager/ConnectionManagerAccess.h \
	../src/base/messages/ChannelSenseRequest_m.h \
	../src/base/messages/MiXiMAirFrame.h \
	../src/base/messages/MiximAirFrame_m.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/BaseDecider.h \
	../src/base/phyLayer/BasePhyLayer.h \
	../src/base/phyLayer/ChannelInfo.h \
	../src/base/phyLayer/ChannelState.h \
	../src/base/phyLayer/Decider.h \
	../src/base/phyLayer/DeciderToPhyInterface.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/MacToPhyInterface.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/PhyUtils.h \
	../src/base/phyLayer/Signal_.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/base/ModuleAccess.h \
	../src/inet_stub/mobility/IMobility.h \
	../src/inet_stub/mobility/models/MobilityAccess.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	../src/modules/phy/SNRThresholdDecider.h \
	decider/DeciderTest.h \
	decider/TestSNRThresholdDeciderNew.h \
	testUtils/OmnetTestBase.h \
	testUtils/asserts.h
$O/mapping/mappingtest.o: mapping/mappingtest.cc \
	../src/base/messages/ChannelSenseRequest_m.h \
	../src/base/phyLayer/BaseDecider.h \
	../src/base/phyLayer/ChannelState.h \
	../src/base/phyLayer/Decider.h \
	../src/base/phyLayer/DeciderToPhyInterface.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/util/FWMath.h \
	../src/modules/phy/Decider802154Narrow.h \
	testUtils/OmnetTestBase.h \
	testUtils/asserts.h
$O/nicTest/NicTests.o: nicTest/NicTests.cc \
	../src/base/modules/BaseModule.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/modules/mac/Mac80211MultiChannel.h \
	nicTest/NicTests.h \
	nicTest/TestApp.h \
	testUtils/OmnetTestBase.h \
	testUtils/TestManager.h \
	testUtils/TestModule.h \
	testUtils/asserts.h
$O/nicTest/TestApp.o: nicTest/TestApp.cc \
	../src/base/modules/BaseModule.h \
	../src/base/utils/FindModule.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/NetwToMacControlInfo.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/modules/mac/Mac80211MultiChannel.h \
	nicTest/TestApp.h \
	testUtils/OmnetTestBase.h \
	testUtils/TestManager.h \
	testUtils/TestModule.h \
	testUtils/asserts.h
$O/power/utils/DeviceDuty.o: power/utils/DeviceDuty.cc \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/modules/power/battery/BatteryState.h \
	power/utils/DeviceDuty.h
$O/power/utils/DeviceDutySimple.o: power/utils/DeviceDutySimple.cc \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/modules/power/battery/BatteryState.h \
	power/utils/DeviceDutySimple.h
$O/power/utils/Subscriber.o: power/utils/Subscriber.cc \
	../src/base/modules/BaseModule.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	power/utils/Subscriber.h
$O/radioState/TestPhyUtils.o: radioState/TestPhyUtils.cc \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/PhyUtils.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	testUtils/OmnetTestBase.h \
	testUtils/asserts.h
$O/testUtils/OmnetTestBase.o: testUtils/OmnetTestBase.cc \
	../src/base/utils/miximkerneldefs.h \
	testUtils/OmnetTestBase.h \
	testUtils/asserts.h
$O/testUtils/TestModule.o: testUtils/TestModule.cc \
	../src/base/utils/FindModule.h \
	../src/base/utils/miximkerneldefs.h \
	testUtils/OmnetTestBase.h \
	testUtils/TestManager.h \
	testUtils/TestModule.h \
	testUtils/asserts.h
$O/testUtils/Testmanager.o: testUtils/Testmanager.cc \
	../src/base/utils/miximkerneldefs.h \
	testUtils/OmnetTestBase.h \
	testUtils/TestManager.h \
	testUtils/asserts.h
$O/testUtils/asserts.o: testUtils/asserts.cc \
	testUtils/asserts.h

