#include "tts_module.h"
#include <cstdlib>
// Includes header.
// For system() call.
void speakText(const std::string &text) { // Defines function for TTS.
std::string cmd = "espeak \"" + text + "\""; 
// Constructs shell command for eSpeak.

system(cmd.c_str());
// Executes the command to speak the text.
}
