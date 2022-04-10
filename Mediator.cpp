
#include "Mediator.h"
#include "LevelGUI.h"


void Mediator::Message(std::string mess) {

	lg->GetMessage(mess);
}
