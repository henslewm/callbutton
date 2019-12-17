<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="19008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="TypeDefs" Type="Folder">
			<Item Name="Button Handler State.ctl" Type="VI" URL="../Button Class/Button Handler State.ctl"/>
			<Item Name="TCP Multiple Connections Data.ctl" Type="VI" URL="../Button Class/TCP Multiple Connections Data.ctl"/>
			<Item Name="TCP Multiple Connections State.ctl" Type="VI" URL="../Button Class/TCP Multiple Connections State.ctl"/>
			<Item Name="icon.ico" Type="Document" URL="../icon.ico"/>
			<Item Name="TCP Message Payload.ctl" Type="VI" URL="../Button Class/TCP Message Payload.ctl"/>
		</Item>
		<Item Name="SubVIs" Type="Folder">
			<Item Name="Message Check.vi" Type="VI" URL="../Message Check.vi"/>
			<Item Name="Parse Message Payload.vi" Type="VI" URL="../TCP Multiple Connections/Parse Message Payload.vi"/>
			<Item Name="Read TCP Message.vi" Type="VI" URL="../TCP Multiple Connections/Read TCP Message.vi"/>
			<Item Name="CallButton TCP Server.vi" Type="VI" URL="../TCP Multiple Connections/CallButton TCP Server.vi"/>
		</Item>
		<Item Name="Button.lvclass" Type="LVClass" URL="../Button Class/Button.lvclass"/>
		<Item Name="Main GUI.vi" Type="VI" URL="../Main GUI.vi"/>
		<Item Name="Error Handler.vi" Type="VI" URL="../Error Handler.vi"/>
<<<<<<< HEAD
		<Item Name="Connection Generator.vi" Type="VI" URL="../Connection Generator.vi"/>
=======
		<Item Name="Fade For Loop.vi" Type="VI" URL="../Fade For Loop.vi"/>
>>>>>>> 07db525602e5505a1943ce8daeba351ab5025922
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="RGB to Color.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/colorconv.llb/RGB to Color.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="Application Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Application Directory.vi"/>
<<<<<<< HEAD
				<Item Name="sub_Random U32.vi" Type="VI" URL="/&lt;vilib&gt;/numeric/sub_Random U32.vi"/>
				<Item Name="Random Number (Range) U64.vi" Type="VI" URL="/&lt;vilib&gt;/numeric/Random Number (Range) U64.vi"/>
				<Item Name="Random Number (Range) I64.vi" Type="VI" URL="/&lt;vilib&gt;/numeric/Random Number (Range) I64.vi"/>
				<Item Name="Random Number (Range) DBL.vi" Type="VI" URL="/&lt;vilib&gt;/numeric/Random Number (Range) DBL.vi"/>
				<Item Name="Random Number (Range).vi" Type="VI" URL="/&lt;vilib&gt;/numeric/Random Number (Range).vi"/>
=======
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="LabVIEWSMTPClient.lvlib" Type="Library" URL="/&lt;vilib&gt;/smtpClient/LabVIEWSMTPClient.lvlib"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
>>>>>>> 07db525602e5505a1943ce8daeba351ab5025922
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="CafeCallButton" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{7B1A4AAC-92F7-4C53-BD1B-4C37897446F8}</Property>
				<Property Name="App_INI_GUID" Type="Str">{856498AF-1F57-4C1C-8525-7D3A3661E4BB}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{4BE7C3B3-10F3-44D8-9229-FF8EDD10E823}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">CafeCallButton</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{D6756A7E-6FAB-41DE-8805-EBB51F750CF9}</Property>
				<Property Name="Bld_version.build" Type="Int">14</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">Application.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/CafeCallButton.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/TypeDefs/icon.ico</Property>
				<Property Name="Source[0].itemID" Type="Str">{0111CAD5-259E-4A9C-9D17-574F02721F11}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Main GUI.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">CafeCallButton</Property>
				<Property Name="TgtF_internalName" Type="Str">CafeCallButton</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2018 </Property>
				<Property Name="TgtF_productName" Type="Str">CafeCallButton</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{05ADFEAE-C480-438D-B729-8820AD5A03D7}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Application.exe</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
		</Item>
	</Item>
</Project>
