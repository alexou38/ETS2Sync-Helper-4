#include "precomp.hpp"
#include "SaveSelector.hpp"

wxDEFINE_EVENT(EVT_SAVE_SELECTED, wxCommandEvent);

wxString SaveSelector::mLabel = "Select %ls Save";
wxString SaveSelector::mFormatZero = "No %ls saves found.";
wxString SaveSelector::mFormatOne = "1 %ls save.";
wxString SaveSelector::mFormatPlural = "%u %ls saves.";

template <> const Ets2::SaveList * SaveSelector::getList() {
	Ets2::Info * ets2Info = getEts2Info();
	if (ets2Info->isValid() && !ets2Info->getProfiles().empty()) {
		return &getEts2Info()->getProfiles()[0]->getSaves();
	} else {
		return nullptr;
	}
}

template <> void SaveSelector::onObjectChanged() {
	QueueEvent(new wxCommandEvent(EVT_SAVE_SELECTED));
}