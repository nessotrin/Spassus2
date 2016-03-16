##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Spassus2
ConfigurationName      :=Debug
WorkspacePath          := "/home/hugo/Casio_DEV/NESSCASDK/CodeliteWorkspace"
ProjectPath            := "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Hugo Kueny
Date                   :=01/09/16
CodeLitePath           :="/home/hugo/.codelite"
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Spassus2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/tools_GameInstance.cpp$(ObjectSuffix) $(IntermediateDirectory)/tools_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/tools_FramerateMonitor.cpp$(ObjectSuffix) $(IntermediateDirectory)/tools_FramerateLimiter.cpp$(ObjectSuffix) $(IntermediateDirectory)/tools_Coord.cpp$(ObjectSuffix) $(IntermediateDirectory)/render_Renderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/render_Screen.cpp$(ObjectSuffix) $(IntermediateDirectory)/world_World.cpp$(ObjectSuffix) $(IntermediateDirectory)/memory_Bitmap.cpp$(ObjectSuffix) $(IntermediateDirectory)/error_Error.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(ObjectSuffix) $(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_Menu.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_MainMenu.cpp$(ObjectSuffix) $(IntermediateDirectory)/tests_ListTests.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "/home/hugo/Casio_DEV/NESSCASDK/CodeliteWorkspace/.build-debug"
	@echo rebuilt > "/home/hugo/Casio_DEV/NESSCASDK/CodeliteWorkspace/.build-debug/Spassus2"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/tools_GameInstance.cpp$(ObjectSuffix): src/tools/GameInstance.cpp $(IntermediateDirectory)/tools_GameInstance.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/tools/GameInstance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tools_GameInstance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tools_GameInstance.cpp$(DependSuffix): src/tools/GameInstance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tools_GameInstance.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tools_GameInstance.cpp$(DependSuffix) -MM "src/tools/GameInstance.cpp"

$(IntermediateDirectory)/tools_GameInstance.cpp$(PreprocessSuffix): src/tools/GameInstance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tools_GameInstance.cpp$(PreprocessSuffix) "src/tools/GameInstance.cpp"

$(IntermediateDirectory)/tools_main.cpp$(ObjectSuffix): src/tools/main.cpp $(IntermediateDirectory)/tools_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/tools/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tools_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tools_main.cpp$(DependSuffix): src/tools/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tools_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tools_main.cpp$(DependSuffix) -MM "src/tools/main.cpp"

$(IntermediateDirectory)/tools_main.cpp$(PreprocessSuffix): src/tools/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tools_main.cpp$(PreprocessSuffix) "src/tools/main.cpp"

$(IntermediateDirectory)/tools_FramerateMonitor.cpp$(ObjectSuffix): src/tools/FramerateMonitor.cpp $(IntermediateDirectory)/tools_FramerateMonitor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/tools/FramerateMonitor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tools_FramerateMonitor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tools_FramerateMonitor.cpp$(DependSuffix): src/tools/FramerateMonitor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tools_FramerateMonitor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tools_FramerateMonitor.cpp$(DependSuffix) -MM "src/tools/FramerateMonitor.cpp"

$(IntermediateDirectory)/tools_FramerateMonitor.cpp$(PreprocessSuffix): src/tools/FramerateMonitor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tools_FramerateMonitor.cpp$(PreprocessSuffix) "src/tools/FramerateMonitor.cpp"

$(IntermediateDirectory)/tools_FramerateLimiter.cpp$(ObjectSuffix): src/tools/FramerateLimiter.cpp $(IntermediateDirectory)/tools_FramerateLimiter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/tools/FramerateLimiter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tools_FramerateLimiter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tools_FramerateLimiter.cpp$(DependSuffix): src/tools/FramerateLimiter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tools_FramerateLimiter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tools_FramerateLimiter.cpp$(DependSuffix) -MM "src/tools/FramerateLimiter.cpp"

$(IntermediateDirectory)/tools_FramerateLimiter.cpp$(PreprocessSuffix): src/tools/FramerateLimiter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tools_FramerateLimiter.cpp$(PreprocessSuffix) "src/tools/FramerateLimiter.cpp"

$(IntermediateDirectory)/tools_Coord.cpp$(ObjectSuffix): src/tools/Coord.cpp $(IntermediateDirectory)/tools_Coord.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/tools/Coord.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tools_Coord.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tools_Coord.cpp$(DependSuffix): src/tools/Coord.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tools_Coord.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tools_Coord.cpp$(DependSuffix) -MM "src/tools/Coord.cpp"

$(IntermediateDirectory)/tools_Coord.cpp$(PreprocessSuffix): src/tools/Coord.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tools_Coord.cpp$(PreprocessSuffix) "src/tools/Coord.cpp"

$(IntermediateDirectory)/render_Renderer.cpp$(ObjectSuffix): src/render/Renderer.cpp $(IntermediateDirectory)/render_Renderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/render/Renderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/render_Renderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/render_Renderer.cpp$(DependSuffix): src/render/Renderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/render_Renderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/render_Renderer.cpp$(DependSuffix) -MM "src/render/Renderer.cpp"

$(IntermediateDirectory)/render_Renderer.cpp$(PreprocessSuffix): src/render/Renderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/render_Renderer.cpp$(PreprocessSuffix) "src/render/Renderer.cpp"

$(IntermediateDirectory)/render_Screen.cpp$(ObjectSuffix): src/render/Screen.cpp $(IntermediateDirectory)/render_Screen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/render/Screen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/render_Screen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/render_Screen.cpp$(DependSuffix): src/render/Screen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/render_Screen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/render_Screen.cpp$(DependSuffix) -MM "src/render/Screen.cpp"

$(IntermediateDirectory)/render_Screen.cpp$(PreprocessSuffix): src/render/Screen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/render_Screen.cpp$(PreprocessSuffix) "src/render/Screen.cpp"

$(IntermediateDirectory)/world_World.cpp$(ObjectSuffix): src/world/World.cpp $(IntermediateDirectory)/world_World.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/world/World.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/world_World.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/world_World.cpp$(DependSuffix): src/world/World.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/world_World.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/world_World.cpp$(DependSuffix) -MM "src/world/World.cpp"

$(IntermediateDirectory)/world_World.cpp$(PreprocessSuffix): src/world/World.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/world_World.cpp$(PreprocessSuffix) "src/world/World.cpp"

$(IntermediateDirectory)/memory_Bitmap.cpp$(ObjectSuffix): src/memory/Bitmap.cpp $(IntermediateDirectory)/memory_Bitmap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/memory/Bitmap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memory_Bitmap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memory_Bitmap.cpp$(DependSuffix): src/memory/Bitmap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memory_Bitmap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/memory_Bitmap.cpp$(DependSuffix) -MM "src/memory/Bitmap.cpp"

$(IntermediateDirectory)/memory_Bitmap.cpp$(PreprocessSuffix): src/memory/Bitmap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memory_Bitmap.cpp$(PreprocessSuffix) "src/memory/Bitmap.cpp"

$(IntermediateDirectory)/error_Error.cpp$(ObjectSuffix): src/error/Error.cpp $(IntermediateDirectory)/error_Error.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/error/Error.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/error_Error.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/error_Error.cpp$(DependSuffix): src/error/Error.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/error_Error.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/error_Error.cpp$(DependSuffix) -MM "src/error/Error.cpp"

$(IntermediateDirectory)/error_Error.cpp$(PreprocessSuffix): src/error/Error.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/error_Error.cpp$(PreprocessSuffix) "src/error/Error.cpp"

$(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(ObjectSuffix): src/keyboard/KeyboardReader.cpp $(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/keyboard/KeyboardReader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(DependSuffix): src/keyboard/KeyboardReader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(DependSuffix) -MM "src/keyboard/KeyboardReader.cpp"

$(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(PreprocessSuffix): src/keyboard/KeyboardReader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/keyboard_KeyboardReader.cpp$(PreprocessSuffix) "src/keyboard/KeyboardReader.cpp"

$(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(ObjectSuffix): src/keyboard/KeyboardSubscription.cpp $(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/keyboard/KeyboardSubscription.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(DependSuffix): src/keyboard/KeyboardSubscription.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(DependSuffix) -MM "src/keyboard/KeyboardSubscription.cpp"

$(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(PreprocessSuffix): src/keyboard/KeyboardSubscription.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/keyboard_KeyboardSubscription.cpp$(PreprocessSuffix) "src/keyboard/KeyboardSubscription.cpp"

$(IntermediateDirectory)/gui_Menu.cpp$(ObjectSuffix): src/gui/Menu.cpp $(IntermediateDirectory)/gui_Menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/gui/Menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_Menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_Menu.cpp$(DependSuffix): src/gui/Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_Menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_Menu.cpp$(DependSuffix) -MM "src/gui/Menu.cpp"

$(IntermediateDirectory)/gui_Menu.cpp$(PreprocessSuffix): src/gui/Menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_Menu.cpp$(PreprocessSuffix) "src/gui/Menu.cpp"

$(IntermediateDirectory)/gui_MainMenu.cpp$(ObjectSuffix): src/gui/MainMenu.cpp $(IntermediateDirectory)/gui_MainMenu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/gui/MainMenu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_MainMenu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_MainMenu.cpp$(DependSuffix): src/gui/MainMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_MainMenu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_MainMenu.cpp$(DependSuffix) -MM "src/gui/MainMenu.cpp"

$(IntermediateDirectory)/gui_MainMenu.cpp$(PreprocessSuffix): src/gui/MainMenu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_MainMenu.cpp$(PreprocessSuffix) "src/gui/MainMenu.cpp"

$(IntermediateDirectory)/tests_ListTests.cpp$(ObjectSuffix): src/memory/tests/ListTests.cpp $(IntermediateDirectory)/tests_ListTests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hugo/Casio_DEV/NESSCASDK/Projects/Spassus2/src/memory/tests/ListTests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tests_ListTests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tests_ListTests.cpp$(DependSuffix): src/memory/tests/ListTests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tests_ListTests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tests_ListTests.cpp$(DependSuffix) -MM "src/memory/tests/ListTests.cpp"

$(IntermediateDirectory)/tests_ListTests.cpp$(PreprocessSuffix): src/memory/tests/ListTests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tests_ListTests.cpp$(PreprocessSuffix) "src/memory/tests/ListTests.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


