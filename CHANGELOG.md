# v1.0.0-beta1
### Added support for ImGui Test Engine
<img src="https://raw.githubusercontent.com/pthom/imgui_bundle/main/bindings/imgui_bundle/doc/doc_images/demo_testengine.jpg" width=200 />

ImGui Test Engine is a Tests & Automation Engine for Dear ImGui. 

* Can be used with python, and C++ (all platforms, incl emscripten). See [python bindings](https://github.com/pthom/imgui_bundle/blob/main/bindings/imgui_bundle/imgui/test_engine.pyi) declarations (stubs).
* Enabled by default inside ImGui Bundle. Needs to be enabled manually when using Hello ImGui.
* Lots of work on making ImGui Test Engine's coroutines (thread based) compatible with Python and emscripten
* ImGui Test Engine is now used to run interactive automations in the [interactive manual](https://traineq.org/ImGuiBundle/emscripten/bin/demo_imgui_bundle.html) (click on the "Show me" buttons)
* Added specific demo and doc

_Note: See [Dear ImGui Test Engine License](https://github.com/ocornut/imgui_test_engine/blob/main/imgui_test_engine/LICENSE.txt). (TL;DR: free for individuals, educational, open-source and small businesses uses. Paid for larger businesses)_

### New library
* Added new library: ImCoolBar
<img src="https://raw.githubusercontent.com/pthom/imgui_bundle/main/bindings/imgui_bundle/doc/doc_images/demo_widgets_coolbar.jpg" width=200>

### Doc
* Completely reviewed the [doc site](https://pthom.github.io/imgui_bundle/).
* Added ["quickstart & example"](https://pthom.github.io/imgui_bundle/quickstart.html) section, with lots of examples
* Added & reviewed [development doc](https://pthom.github.io/imgui_bundle/devel_docs/index.html)
* Added specific [doc / bindings maintenance](https://pthom.github.io/imgui_bundle/devel_docs/bindings.html) (and how to add bindings for new libraries)

### Misc
* Python bindings stubs: add @overload everywhere when required
* cmake: add options to run sanitizers (no warning given by any of them at this moment)
* demo_logger: add logs at startup
* implot python bindings: add plot_bar_groups & plot_pie_chart
* update imgui_toggle (after merged PRs from imgui_bundle)
* update HelloImGui: add callback BeforeImGuiRender
* update ImmVision: can call gladLoadGl if needed (fix #134)
* add demo imgui_example_glfw_opengl3.cpp


# v0.9.0
* Added wheels for python3.12
Submodule updates:
* imgui-node-editor: fix suspend/resume issue
* HelloImGui::DockingParams::focusDockableWindow() can show a window tab


# v0.8.8
* update imgui to v1.89.6 and implot to v0.17
* Enable 32 bits ImDrawIdx for ImPlot
Submodules changes:
* ImmVision: fix exit sequence, can save colormap image
* imgui-node-editor: fixes
* HelloImGui: basic apps can run without font assets / can set docking options for main dock space


# v0.8.7
### Updates and new features
* ImGui: updated imgui to v1.89.6 (May 2023)
* ImGui: python bindings now can use [SDL2](https://github.com/pthom/imgui_bundle/blob/main/bindings/imgui_bundle/demos_python/demos_immapp/imgui_example_sdl2_opengl3.py) (glfw is of course still supported, and remains the default with Hello ImGui)
* ImGui: Add python bindings for drag&drop
* HelloImGui: can now handle several layouts and save settings per layout (see details below)
* HelloImGui: can now store user defined settings in the ini file
* HelloImGui: now remembers user choices for the theme, status bar, and fps throttling
* HelloImGui: handle utf8 filenames for assets loading
* ImGuiColorTextEdit is now based on @santaclose [fork](https://github.com/santaclose/ImGuiColorTextEdit)
* immvision bindings: use shared memory (between python and C++) for images
* ImPlot bindings: Add support for colormap in implot python bindings
* ImPlot bindings: Add support for heatmaps

As always, an online interactive manual is available
[<img src="https://raw.githubusercontent.com/pthom/imgui_bundle/doc/bindings/imgui_bundle/doc/doc_images/badge_interactive_manual.png" height=20>](https://traineq.org/ImGuiBundle/emscripten/bin/demo_imgui_bundle.html)&nbsp;&nbsp;&nbsp;[<img src="https://raw.githubusercontent.com/pthom/imgui_bundle/doc/bindings/imgui_bundle/doc/doc_images/badge_view_docs.png" height=20>](https://pthom.github.io/imgui_bundle)

### More details about layouts handling with Hello ImGui:

![Layout demo](https://traineq.org/ImGuiBundle/HelloImGuiLayout.gif)

Each layout has a different spatial layout and can contain a different list of windows. Each layout also remembers the user modifications to this given layout, as well as the  list of opened windows.

See [this online emscripten demo](https://traineq.org/ImGuiBundle/emscripten/bin/demo_docking.html)  of the docking and layout, the  [C++ demo code](https://github.com/pthom/imgui_bundle/blob/main/bindings/imgui_bundle/demos_cpp/demos_immapp/demo_docking.cpp), and [python demo code](https://github.com/pthom/imgui_bundle/blob/main/bindings/imgui_bundle/demos_python/demos_immapp/demo_docking.py)

For more explanations on how to handle complex layouts, see this [video explanation on YouTube](https://www.youtube.com/watch?v=XKxmz__F4ow) (5 minutes)


# v0.8.6
Please use v0.8.7 instead


# v0.8.5
Hello ImGui and ImmApp usability improvements:
* customize menu App
* Docking Layout: keep user preferences
* improve windows initial layout


# v0.8.3
Added python bindings for implot_internal

Minor improvements:
- Improve font rendering
- Improve emscripten idling mode
- Review main theme (DarculaDarker) to make it easier on the eyes


# v0.8.2
* Autoresize window post startup
* Corrected notebook rendering


# v0.8.1
* correct launch demo_node_editor_basic


# v0.8.0
* markdown: render code blocks with text editor, and make them easily copyable
* add lots of demos
* add doc / ascii_doc
* add emscripten interactive manual
* add immapp::snippets
* add portable_file_dialogs


# v0.7.2
* Improved doc and notebook support


# v0.7.1
*   Improved support for High DPI in third parties
*   Improved demos
*   Markdown now support code blocks


# v0.7.0 (work in progress)
* Added support for [ImGuizmo](https://github.com/CedricGuillemet/ImGuizmo)
  * all components available in C++ (gizmo, curve, graph, sequencer, etc.)
  * added [ImGuizmoPure](external/ImGuizmo/ImGuizmoPure): C++ wrappers around existing api with clearly marked inputs and outputs
  * for python: ported pure API
  * added set of twin demos showing usage [with C++](bindings/imgui_bundle/demos_cpp/demos_imguizmo) and [with python](bindings/imgui_bundle/demos/demos_imguizmo). A good example showing how to port features between C++ and python.
  * the following items could not be ported to python (making a pure wrapper failed): ImGradient, GraphEditor, Sequencer
* Added support for [imgui_tex_inspect](https://github.com/andyborrell/imgui_tex_inspect), a texture inspector.
  * Added support for codeless init of imgui_tex_inspect when using ImGuiBundle runner (future ImmApp), thanks to AddOnParams::withTexInspect
* 6ef5df64: added imgui.set_io_ini_filename() & imgui.set_io_log_filename()
  Manual binding for ImGuiIO::IniFilename (naked const char* pointer)
* 778aabf3: Added imgui_bundle.em_size and visible_font_size():
In order to scale your widgets properly on all platforms, use multiples of this size.
(on MacOS with retina FontGlobalScale can be equal to 2)
(EmSize is an alias for VisibleFontSize)
* f6ae2072: generate named constructors if there is *no* user defined constructors
* 19ca013a: remove ImGui prefix from classes and enums => lots of API changes
* f9210578: ImPlot bindings: remove prefix ImPlot from classes and enums
* hardened stub typings with mypy
* imgui.backends: replace open_gl3 by opengl3
* immvision module now stable
* Lots of work on the CI and wheel generation


# v0.6.6
#### Added Immvision (image debugger and analyzer utility)
immvision will be compiled if OpenCV is available.
immvision is not available by default on the pip bindings.

To add them, compile from source [after having installed conan](https://github.com/pthom/imgui_bundle/blob/v0.6.6/external/immvision/find_opencv.cmake#L5)

#### Added theming
* [Demo](https://www.youtube.com/watch?v=Hhartw0cUjg)
* [API](https://github.com/pthom/imgui_bundle/blob/v0.6.6/bindings/imgui_bundle/hello_imgui.pyi#L375)
* Default theme is now a variation on Darcula

#### Improve ImGui & Glfw,  low level integration
* glfw is now linked as a dynamic library
* support [any glfw callback](https://github.com/pthom/imgui_bundle/blob/v0.6.6/bindings/imgui_bundle/demos/demo_imgui_bundle.py#L119)
* added low level binding for [imgui backends](https://github.com/pthom/imgui_bundle/blob/main/bindings/imgui_bundle/imgui_backends.pyi) glfw and OpenGl3
* imgui apps can now be written from scratch : as an example, ported [imgui/examples/example_glfw_opengl3/main.cpp](https://github.com/ocornut/imgui/blob/master/examples/example_glfw_opengl3/main.cpp) to python [imgui_example_glfw_opengl3.py](https://github.com/pthom/imgui_bundle/blob/main/bindings/imgui_bundle/demos/imgui_example_glfw_opengl3.py)

**Full Changelog**: https://github.com/pthom/imgui_bundle/compare/v0.6.5...v0.6.6


# v0.6.5
Lots of additions
* Fine tune window geometry:
  * save & restore window position & size
  * support for full screen
  * auto size window from its inner widgets
  * handle high dpi (especially on windows)
* Crisp fonts on MacOS
* Backend support: can switch between sdl and glfw
* Added python support to ImGuiColorTextEdit
* Powersave: reduce app fps when idle
* Add toggle switches from https://github.com/cmdwtf/imgui_toggle.git
* Support for jupyter notebook (with inline screenshots), via `imgui_bundle.run_nb`
  (see https://github.com/pthom/imgui_bundle/blob/main/bindings/imgui_bundle/demos/notebooks/demo_notebook.ipynb)

**Full Changelog**: https://github.com/pthom/imgui_bundle/compare/v0.6.4...v0.6.5

