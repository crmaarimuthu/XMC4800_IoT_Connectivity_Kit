<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="EVENT_DETECTOR" URI="http://resources/4.0.8/app/EVENT_DETECTOR/0" description="Provides the configuration for Event Request Source &#xA;and Event Trigger Logic units of ERU" version="4.0.8" minDaveVersion="4.0.0" instanceLabel="EVENT_DETECTOR_0" appLabel="">
  <properties provideInit="true" sharable="true"/>
  <virtualSignals name="signal_a" URI="http://resources/4.0.8/app/EVENT_DETECTOR/0/vs_event_detector_input_A" hwSignal="a" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../DIGITAL_IO/v4_0_18/DIGITAL_IO_1.app#//@connections.2"/>
  </virtualSignals>
  <virtualSignals name="signal_b" URI="http://resources/4.0.8/app/EVENT_DETECTOR/0/vs_event_detector_input_B" hwSignal="b" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="trigger_out" URI="http://resources/4.0.8/app/EVENT_DETECTOR/0/vs_event_detector_TriggerPulse" hwSignal="tr" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="status" URI="http://resources/4.0.8/app/EVENT_DETECTOR/0/vs_event_detector_FlagStatus" hwSignal="fl" hwResource="//@hwResources.0" visible="true"/>
  <hwResources name="ers_etl" URI="http://resources/4.0.8/app/EVENT_DETECTOR/0/hwres_eru_ers_etl" resourceGroupUri="peripheral/eru/*/ers_etl/*" mResGrpUri="peripheral/eru/*/ers_etl/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/eru0/eru0_0.dd#//@provided.0"/>
  </hwResources>
  <connections URI="http://resources/4.0.8/app/EVENT_DETECTOR/0/http://resources/4.0.8/app/EVENT_DETECTOR/0/vs_event_detector_TriggerPulse/http://resources/4.1.16/app/EVENT_GENERATOR/0/vs_event_generator_trin" sourceSignal="trigger_out" targetSignal="trigger_in" srcVirtualSignal="//@virtualSignals.2">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../EVENT_GENERATOR/v4_1_16/EVENT_GENERATOR_0.app#//@virtualSignals.1"/>
    <targetVirtualSignal href="../../EVENT_GENERATOR/v4_1_16/EVENT_GENERATOR_0.app#//@virtualSignals.1"/>
  </connections>
</ResourceModel:App>
