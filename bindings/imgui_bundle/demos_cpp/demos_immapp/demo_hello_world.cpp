#include "immapp/immapp.h"
#include "imgui.h"

void Gui()
{
    ImGui::Text("Hello, world!");
}

int main(int, char **)
{
    ImmApp::Run(
        Gui,
        "Hello!",
        true // window_size_auto
        // Uncomment the next line to restore window position and size from previous run
        // window_restore_previous_geometry==true
    );

    return 0;
}
