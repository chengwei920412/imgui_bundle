#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include <pybind11/stl_bind.h>

#include "immapp/immapp.h"
#include "imgui-node-editor/imgui_node_editor_internal.h"

namespace py = pybind11;


namespace ax
{
    namespace NodeEditor
    {
        // using EditorContext = Detail::EditorContext;
        struct EditorContext: public Detail::EditorContext {};
    }
}




// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#include <string>
#include <vector>


template<typename T, int N>
struct FixedSizeMemberArray
{
    const T& operator[](size_t i) const { return Values[i];}
    T& operator[](size_t i) { return Values[i];}

    T& __getitem__(size_t i)
    {
        IM_ASSERT((i >= 0) && (i < N));
        return Values[i];
    }

    void __setitem__(size_t i, T&& v)
    {
        IM_ASSERT((i >= 0) && (i < N));
        Values[i] == std::move(v);
    }
private:
    T Values[N];
};


struct Greet
{
    std::string Greeting = "Hello, ";
    std::string Name = "Pascal";

    Greet() { std::cout << "Construct\n"; }
    Greet(const Greet& other) { std::cout << "Copy\n"; Greeting = other.Greeting; Name = other.Greeting; }
    ~Greet() { std::cout << "Destruct\n"; }
    Greet& operator=(const Greet& other) { std::cout << "Operator=\n"; Greeting = other.Greeting; Name = other.Greeting; return *this;}

    std::string __repr__() { return Greeting + Name; }
};


struct GreetList
{
    // Requiring the user to replace all occurrences of fixed size arrays is probably a bad idea,
    // because it would require too many modification in external libraries
    //
    //FixedSizeMemberArray<Greet, 12> Greets;

    Greet Greets[12];
};




void py_init_module_immapp_cpp(py::module& m)
{
    using namespace ImmApp;

    auto pyClassGreet =
        py::class_<Greet>
            (m, "Greet", "")
            .def(py::init<>([](
                     std::string Greeting = "Hello, ", std::string Name = "Pascal")
                            {
                                auto r = std::make_unique<Greet>();
                                r->Greeting = Greeting;
                                r->Name = Name;
                                return r;
                            })
                , py::arg("greeting") = "Hello, ", py::arg("name") = "Pascal"
            )
            .def_readwrite("greeting", &Greet::Greeting, "")
            .def_readwrite("name", &Greet::Name, "")
            .def("__repr__",
                 &Greet::__repr__)
    ;


    /*
    The current binding enables this kind of interaction. Is there a better way?

    >>> import imgui_bundle
    >>> g = imgui_bundle.immapp.GreetList()
    >>> g.greet(0)
    Hello, Pascal
    >>> g.greet(0).name = "Diederick"
    >>> g.greet(0)
    Hello, Diederick
    >>> g.set_greet(0, imgui_bundle.immapp.Greet("Bonjour, ", "Diederick"))
    >>> g.greet(0)
    Bonjour, Diederick
     */
    auto pyClassGreetList =
        py::class_<GreetList>
            (m, "GreetList", "")
            .def(py::init<>())

            .def("greet", [](GreetList& self, size_t i) -> Greet& { return self.Greets[i]; }, py::return_value_policy::reference )
            .def("set_greet", [](GreetList& self, size_t i, const Greet& v) { self.Greets[i] = v; } )
    ;


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:immapp.h>    ////////////////////
    ////////////////////    </generated_from:immapp.h>    ////////////////////


    ////////////////////    <generated_from:runner.h>    ////////////////////
    auto pyClassAddOnsParams =
        py::class_<ImmApp::AddOnsParams>
            (m, "AddOnsParams", " AddOnParams: require specific ImGuiBundle packages (markdown, node editor, texture viewer)\n to be initialized at startup.")
        .def(py::init<>([](
        bool withImplot = false, bool withMarkdown = false, bool withNodeEditor = false, bool withTexInspect = false, std::optional<NodeEditorConfig> withNodeEditorConfig = std::nullopt, std::optional<ImGuiMd::MarkdownOptions> withMarkdownOptions = std::nullopt)
        {
            auto r = std::make_unique<AddOnsParams>();
            r->withImplot = withImplot;
            r->withMarkdown = withMarkdown;
            r->withNodeEditor = withNodeEditor;
            r->withTexInspect = withTexInspect;
            r->withNodeEditorConfig = withNodeEditorConfig;
            r->withMarkdownOptions = withMarkdownOptions;
            return r;
        })
        , py::arg("with_implot") = false, py::arg("with_markdown") = false, py::arg("with_node_editor") = false, py::arg("with_tex_inspect") = false, py::arg("with_node_editor_config") = py::none(), py::arg("with_markdown_options") = py::none()
        )
        .def_readwrite("with_implot", &AddOnsParams::withImplot, "Set withImplot=True if you need to plot graphs")
        .def_readwrite("with_markdown", &AddOnsParams::withMarkdown, " Set withMarkdown=True if you need to render Markdown\n (alternatively, you can set withMarkdownOptions)")
        .def_readwrite("with_node_editor", &AddOnsParams::withNodeEditor, " Set withNodeEditor=True if you need to render a node editor\n (alternatively, you can set withNodeEditorConfig)")
        .def_readwrite("with_tex_inspect", &AddOnsParams::withTexInspect, "Set withTexInspect=True if you need to use imgui_tex_inspect")
        .def_readwrite("with_node_editor_config", &AddOnsParams::withNodeEditorConfig, "You can tweak NodeEditorConfig (but this is optional)")
        .def_readwrite("with_markdown_options", &AddOnsParams::withMarkdownOptions, "You can tweak MarkdownOptions (but this is optional)")
        ;


    m.def("run",
        py::overload_cast<HelloImGui::RunnerParams &, const ImmApp::AddOnsParams &>(ImmApp::Run), py::arg("runner_params"), py::arg("add_ons_params") = ImmApp::AddOnsParams());

    m.def("run",
        py::overload_cast<const HelloImGui::SimpleRunnerParams &, const ImmApp::AddOnsParams &>(ImmApp::Run), py::arg("simple_params"), py::arg("add_ons_params") = ImmApp::AddOnsParams());

    m.def("run",
        py::overload_cast<const VoidFunction &, const std::string &, bool, bool, const ScreenSize &, float, bool, bool, bool, bool, const std::optional<NodeEditorConfig> &, const std::optional<ImGuiMd::MarkdownOptions> &>(ImmApp::Run),
        py::arg("gui_function"), py::arg("window_title") = "", py::arg("window_size_auto") = false, py::arg("window_restore_previous_geometry") = false, py::arg("window_size") = ImmApp::DefaultScreenSize, py::arg("fps_idle") = 10.f, py::arg("with_implot") = false, py::arg("with_markdown") = false, py::arg("with_node_editor") = false, py::arg("with_tex_inspect") = false, py::arg("with_node_editor_config") = py::none(), py::arg("with_markdown_options") = py::none(),
        " Helper to run an app inside imgui_bundle, using HelloImGui:\n\n (HelloImGui::SimpleRunnerParams)\n     - `guiFunction`: the function that will render the ImGui widgets\n     - `windowTitle`: title of the window\n     - `windowSizeAuto`: if True, autosize the window from its inner widgets\n     - `windowRestorePreviousGeometry`: if True, restore window size and position from last run\n     - `windowSize`: size of the window\n     - `fpsIdle`: fps of the application when idle\n\n (ImmApp::AddOnsParams)\n     - `with_implot`: if True, then a context for implot will be created/destroyed automatically\n     - `with_markdown` / `with_markdown_options`: if specified, then  the markdown context will be initialized\n       (i.e. required fonts will be loaded)\n     - `with_node_editor` / `with_node_editor_config`: if specified, then a context for imgui_node_editor\n       will be created automatically.");

    m.def("em_size",
        ImmApp::EmSize, " EmSize() returns the visible font size on the screen. For good results on HighDPI screens, always scale your\n widgets and windows relatively to this size.\n It is somewhat comparable to the [em CSS Unit](https://lyty.dev/css/css-unit.html).\n EmSize() = ImGui::GetFontSize()");

    m.def("em_vec2",
        py::overload_cast<float, float>(ImmApp::EmVec2), py::arg("x"), py::arg("y"));

    m.def("em_vec2",
        py::overload_cast<ImVec2>(ImmApp::EmVec2), py::arg("v"));
    ////////////////////    </generated_from:runner.h>    ////////////////////


    ////////////////////    <generated_from:utils.h>    ////////////////////
    m.def("clock_seconds",
        ImmApp::ClockSeconds, "Chronometer in seconds");

    m.def("current_node_editor_context",
        ImmApp::CurrentNodeEditorContext);

    m.def("suspend_node_editor_canvas",
        ImmApp::SuspendNodeEditorCanvas);

    m.def("resume_node_editor_canvas",
        ImmApp::ResumeNodeEditorCanvas);
    ////////////////////    </generated_from:utils.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
