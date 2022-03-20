#
# OMNeT++/OMNEST Makefile for miximexamples
#
# This file was generated with the command:
#  opp_makemake -f --deep -o miximexamples -O out -I../src/base/modules -I../src/inet_stub/networklayer/common -I../src -I../src/modules/utility -I../src/base/utils -I../src/inet_stub/mobility/models -I../src/modules/phy -I../src/base -I../src/modules/obstacle -I../src/base/phyLayer -I../src/inet_stub/mobility -I../src/modules/analogueModel -I../src/inet_stub/util -I../src/modules/messages -I../src/inet_stub/linklayer/contract -I../src/base/connectionManager -I../src/inet_stub/base -I../src/base/messages -I../src/modules -L../out/$$\(CONFIGNAME\)/src -lmixim -DWITH_MIXIM_EXAMPLES -DMIXIM_INET
#

# Name of target to be created (-o option)
TARGET = miximexamples$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../src/base/modules \
    -I../src/inet_stub/networklayer/common \
    -I../src \
    -I../src/modules/utility \
    -I../src/base/utils \
    -I../src/inet_stub/mobility/models \
    -I../src/modules/phy \
    -I../src/base \
    -I../src/modules/obstacle \
    -I../src/base/phyLayer \
    -I../src/inet_stub/mobility \
    -I../src/modules/analogueModel \
    -I../src/inet_stub/util \
    -I../src/modules/messages \
    -I../src/inet_stub/linklayer/contract \
    -I../src/base/connectionManager \
    -I../src/inet_stub/base \
    -I../src/base/messages \
    -I../src/modules \
    -I. \
    -ICSMAMac \
    -IMac80211 \
    -IWSNRouting \
    -IanalogueModels \
    -IbaseNetwork \
    -Ibmac \
    -Ibmac/results \
    -Iieee802154Narrow \
    -Iieee802154a \
    -Iieee802154a/channels \
    -Iieee802154a/channels/noshadow \
    -Iieee802154a/channels/shadow \
    -Iieee802154a/receivers \
    -Ilmac \
    -ImultiConnectionManager \
    -Iobstacles

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../out/$(CONFIGNAME)/src  -lmixim
LIBS += -Wl,-rpath,`abspath ../out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = examples
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/CSMAMac/SimpleNetwLayer.o \
    $O/analogueModels/RandomFreqTimeModel.o \
    $O/analogueModels/RandomFrequencyOnlyModel.o \
    $O/analogueModels/SamplePhyLayer.o \
    $O/analogueModels/SimpleMacLayer.o \
    $O/ieee802154Narrow/NetworkStackTrafficGen.o \
    $O/ieee802154Narrow/WorldUtilityStats.o

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
	$(Q)-rm -f miximexamples miximexamples.exe libmiximexamples.so libmiximexamples.a libmiximexamples.dll libmiximexamples.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f CSMAMac/*_m.cc CSMAMac/*_m.h
	$(Q)-rm -f Mac80211/*_m.cc Mac80211/*_m.h
	$(Q)-rm -f WSNRouting/*_m.cc WSNRouting/*_m.h
	$(Q)-rm -f analogueModels/*_m.cc analogueModels/*_m.h
	$(Q)-rm -f baseNetwork/*_m.cc baseNetwork/*_m.h
	$(Q)-rm -f bmac/*_m.cc bmac/*_m.h
	$(Q)-rm -f bmac/results/*_m.cc bmac/results/*_m.h
	$(Q)-rm -f ieee802154Narrow/*_m.cc ieee802154Narrow/*_m.h
	$(Q)-rm -f ieee802154a/*_m.cc ieee802154a/*_m.h
	$(Q)-rm -f ieee802154a/channels/*_m.cc ieee802154a/channels/*_m.h
	$(Q)-rm -f ieee802154a/channels/noshadow/*_m.cc ieee802154a/channels/noshadow/*_m.h
	$(Q)-rm -f ieee802154a/channels/shadow/*_m.cc ieee802154a/channels/shadow/*_m.h
	$(Q)-rm -f ieee802154a/receivers/*_m.cc ieee802154a/receivers/*_m.h
	$(Q)-rm -f lmac/*_m.cc lmac/*_m.h
	$(Q)-rm -f multiConnectionManager/*_m.cc multiConnectionManager/*_m.h
	$(Q)-rm -f obstacles/*_m.cc obstacles/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc CSMAMac/*.cc Mac80211/*.cc WSNRouting/*.cc analogueModels/*.cc baseNetwork/*.cc bmac/*.cc bmac/results/*.cc ieee802154Narrow/*.cc ieee802154a/*.cc ieee802154a/channels/*.cc ieee802154a/channels/noshadow/*.cc ieee802154a/channels/shadow/*.cc ieee802154a/receivers/*.cc lmac/*.cc multiConnectionManager/*.cc obstacles/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/CSMAMac/SimpleNetwLayer.o: CSMAMac/SimpleNetwLayer.cc \
	CSMAMac/SimpleNetwLayer.h \
	../src/base/messages/NetwPkt_m.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseLayer.h \
	../src/base/modules/BaseMacLayer.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/utils/FindModule.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MacToNetwControlInfo.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/NetwToMacControlInfo.h \
	../src/base/utils/PassedMessage.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/linklayer/contract/MACAddress.h
$O/analogueModels/RandomFreqTimeModel.o: analogueModels/RandomFreqTimeModel.cc \
	analogueModels/RandomFreqTimeModel.h \
	../src/base/messages/MiXiMAirFrame.h \
	../src/base/messages/MiximAirFrame_m.h \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/Signal_.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h
$O/analogueModels/RandomFrequencyOnlyModel.o: analogueModels/RandomFrequencyOnlyModel.cc \
	analogueModels/RandomFrequencyOnlyModel.h \
	../src/base/messages/MiXiMAirFrame.h \
	../src/base/messages/MiximAirFrame_m.h \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/Mapping.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/phyLayer/MappingUtils.h \
	../src/base/phyLayer/Signal_.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h
$O/analogueModels/SamplePhyLayer.o: analogueModels/SamplePhyLayer.cc \
	analogueModels/RandomFreqTimeModel.h \
	analogueModels/RandomFrequencyOnlyModel.h \
	analogueModels/SamplePhyLayer.h \
	analogueModels/ThresholdDecider.h \
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
	../src/modules/phy/PhyLayer.h
$O/analogueModels/SimpleMacLayer.o: analogueModels/SimpleMacLayer.cc \
	analogueModels/SimpleMacLayer.h \
	../src/base/messages/MacPkt_m.h \
	../src/base/modules/BaseModule.h \
	../src/base/phyLayer/AnalogueModel.h \
	../src/base/phyLayer/ChannelState.h \
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
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h
$O/ieee802154Narrow/NetworkStackTrafficGen.o: ieee802154Narrow/NetworkStackTrafficGen.cc \
	ieee802154Narrow/NetworkStackTrafficGen.h \
	../src/base/messages/NetwPkt_m.h \
	../src/base/modules/AddressingInterface.h \
	../src/base/modules/ArpInterface.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseLayer.h \
	../src/base/modules/BaseMacLayer.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/BaseWorldUtility.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/phyLayer/Interpolation.h \
	../src/base/phyLayer/MappingBase.h \
	../src/base/utils/FindModule.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/NetwToMacControlInfo.h \
	../src/base/utils/PassedMessage.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	../src/modules/utility/Packet.h
$O/ieee802154Narrow/WorldUtilityStats.o: ieee802154Narrow/WorldUtilityStats.cc \
	ieee802154Narrow/WorldUtilityStats.h \
	../src/base/modules/BaseBattery.h \
	../src/base/modules/BaseLayer.h \
	../src/base/modules/BaseModule.h \
	../src/base/modules/BaseWorldUtility.h \
	../src/base/modules/MiximBatteryAccess.h \
	../src/base/utils/FindModule.h \
	../src/base/utils/HostState.h \
	../src/base/utils/MiXiMDefs.h \
	../src/base/utils/PassedMessage.h \
	../src/base/utils/SimpleAddress.h \
	../src/base/utils/miximkerneldefs.h \
	../src/inet_stub/base/Coord.h \
	../src/inet_stub/base/INETDefs.h \
	../src/inet_stub/linklayer/contract/MACAddress.h \
	../src/inet_stub/util/2DVector.h \
	../src/inet_stub/util/FWMath.h \
	../src/modules/utility/Packet.h

