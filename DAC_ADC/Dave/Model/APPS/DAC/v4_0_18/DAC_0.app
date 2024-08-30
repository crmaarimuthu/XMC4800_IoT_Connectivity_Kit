<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="DAC" URI="http://resources/4.0.18/app/DAC/0" description="Generates Pattern, Noise and Ramp waveform.&#xA; It can be used for single value and data processing modes." mode="NOTSHARABLE" version="4.0.18" minDaveVersion="4.0.0" instanceLabel="DAC_0" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="analog_ch_output" URI="http://resources/4.0.18/app/DAC/0/vs_dac_output" hwSignal="out" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="trigger" URI="http://resources/4.0.18/app/DAC/0/vs_dac_trigger" hwSignal="trig" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="sign" URI="http://resources/4.0.18/app/DAC/0/vs_dac_sgn" hwSignal="sgn" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="event_ch_sr" URI="http://resources/4.0.18/app/DAC/0/vs_dac_sr" hwSignal="sr" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="pad_signal" URI="http://resources/4.0.18/app/DAC/0/vs_io_pad" hwSignal="pad" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="Pin_signal" URI="http://resources/4.0.18/app/DAC/0/__pin_vs_io_pad" hwSignal="pin" hwResource="//@hwResources.2"/>
  <requiredApps URI="http://resources/4.0.18/app/DAC/0/appres_clock_0" requiredAppName="CLOCK_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK_XMC4/v4_0_24/CLOCK_XMC4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.18/app/DAC/0/appres_analog_io" requiredAppName="ANALOG_IO" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../ANALOG_IO/v4_0_12/ANALOG_IO_2.app#/"/>
  </requiredApps>
  <hwResources name="DAC Channel" URI="http://resources/4.0.18/app/DAC/0/hwres_dac_slice" resourceGroupUri="peripheral/dac/*/slice/*" mResGrpUri="peripheral/dac/*/slice/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/dac/dac_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="Pin" URI="http://resources/4.0.18/app/DAC/0/hwres_dac_analogpin" resourceGroupUri="" required="false" solverVariable="true" mResGrpUri="port/p/sv0/pad/*">
    <solverVarMap index="2">
      <value variableName="sv0" solverValue="14"/>
    </solverVarMap>
    <solverVarMap index="2">
      <value variableName="sv0" solverValue="14"/>
    </solverVarMap>
  </hwResources>
  <hwResources name="Pin" URI="http://resources/4.0.18/app/DAC/0/__pin_hwres_dac_analogpin" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <connections URI="http://resources/4.0.18/app/DAC/0/http://resources/4.0.18/app/DAC/0/vs_dac_output/http://resources/4.0.18/app/DAC/0/vs_io_pad" systemDefined="true" sourceSignal="analog_ch_output" targetSignal="pad_signal" required="false" srcVirtualSignal="//@virtualSignals.0" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.0.18/app/DAC/0/http://resources/4.0.18/app/DAC/0/vs_dac_output/http://resources/4.0.18/app/DAC/0/vsra_analog_io_pin" systemDefined="true" sourceSignal="analog_ch_output" targetSignal="pin" srcVirtualSignal="//@virtualSignals.0" proxyTargetVirtualSignalUri="http://resources/4.0.12/app/ANALOG_IO/0/vs_analog_io_pad_pin" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../ANALOG_IO/v4_0_12/ANALOG_IO_2.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../ANALOG_IO/v4_0_12/ANALOG_IO_2.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.18/app/DAC/0/http://resources/4.0.18/app/DAC/0/vs_io_pad/http://resources/4.0.18/app/DAC/0/__pin_vs_io_pad" systemDefined="true" sourceSignal="pad_signal" targetSignal="Pin_signal" srcVirtualSignal="//@virtualSignals.4" targetVirtualSignal="//@virtualSignals.5"/>
  <connections URI="http://resources/4.0.18/app/DAC/0/http://resources/4.0.18/app/DAC/0/__pin_vs_io_pad/http://resources/4.0.18/app/DAC/0/vs_io_pad" systemDefined="true" sourceSignal="Pin_signal" targetSignal="pad_signal" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.4"/>
</ResourceModel:App>
