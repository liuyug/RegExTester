/***************************************************************
 * Name:      RegExTesterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Liu Yu Gang ()
 * Created:   2008-08-29
 * Copyright: Liu Yu Gang ()
 * License:
 **************************************************************/

#include "RegExTesterMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(RegExTesterDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/clipbrd.h>
#include <wx/dataobj.h>
#include <wx/settings.h>
#include <wx/aboutdlg.h>

#include "version.h"

#include "regex_16.xpm"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(RegExTesterDialog)
const long RegExTesterDialog::ID_STATICTEXT1 = wxNewId();
const long RegExTesterDialog::ID_TEXTCTRL1 = wxNewId();
const long RegExTesterDialog::ID_BUTTON3 = wxNewId();
const long RegExTesterDialog::ID_BUTTON4 = wxNewId();
const long RegExTesterDialog::ID_STATICTEXT2 = wxNewId();
const long RegExTesterDialog::ID_CHOICE1 = wxNewId();
const long RegExTesterDialog::ID_CHECKBOX1 = wxNewId();
const long RegExTesterDialog::ID_CHECKBOX2 = wxNewId();
const long RegExTesterDialog::ID_STATICTEXT3 = wxNewId();
const long RegExTesterDialog::ID_TEXTCTRL2 = wxNewId();
const long RegExTesterDialog::ID_LISTCTRL1 = wxNewId();
const long RegExTesterDialog::ID_BUTTON1 = wxNewId();
const long RegExTesterDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RegExTesterDialog,wxDialog)
    //(*EventTable(RegExTesterDialog)
    //*)
END_EVENT_TABLE()

RegExTesterDialog::RegExTesterDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(RegExTesterDialog)
    wxBoxSizer* BoxSizer4;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, id, _("Regular Expression Tester"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Regular expression:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrlRegEx = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(672,104), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(TextCtrlRegEx, 1, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    ButtonRegExMatch = new wxButton(this, ID_BUTTON3, _("Match"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer1->Add(ButtonRegExMatch, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonCopyAsCpp = new wxButton(this, ID_BUTTON4, _("Copy as C++"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer1->Add(ButtonCopyAsCpp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(FlexGridSizer1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("RegEx library:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer4->Add(StaticText2, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceRegExLib = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(198,22), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    BoxSizer4->Add(ChoiceRegExLib, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBoxCaseInsensitive = new wxCheckBox(this, ID_CHECKBOX1, _("Case insensitive"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBoxCaseInsensitive->SetValue(false);
    BoxSizer4->Add(CheckBoxCaseInsensitive, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBoxMatchNewlines = new wxCheckBox(this, ID_CHECKBOX2, _("Match newlines"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBoxMatchNewlines->SetValue(false);
    BoxSizer4->Add(CheckBoxMatchNewlines, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Text:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer1->Add(StaticText3, 0, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlText = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(854,343), wxTE_MULTILINE|wxTE_RICH|wxTE_DONTWRAP, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer1->Add(TextCtrlText, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListCtrlRegExResult = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(685,159), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer1->Add(ListCtrlRegExResult, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RegExTesterDialog::OnButtonRegExMatchClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RegExTesterDialog::OnButtonCopyAsCppClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&RegExTesterDialog::OnListCtrlRegExResultItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&RegExTesterDialog::OnListCtrlRegExResultItemDeselect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RegExTesterDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RegExTesterDialog::OnQuit);
    //*)
    TextCtrlText->Connect(ID_TEXTCTRL2,wxEVT_SET_FOCUS,(wxObjectEventFunction)&RegExTesterDialog::OnTextCtrlTextFocusEvent,NULL,this);
	SetIcon(wxICON(regex_16));
    Center();
    m_bNewMatch=true;
    m_nStartPos=0;
    m_nEndPos=0;
    ChoiceRegExLib->Append(wxT("wxWidgets (wxRE_EXTENDED)"));
    ChoiceRegExLib->Append(wxT("wxWidgets (wxRE_ADVANCED)"));
    ChoiceRegExLib->Append(wxT("wxWidgets (wxRE_BASIC)"));
    ChoiceRegExLib->SetSelection(0);

    int col=0;
    ListCtrlRegExResult->InsertColumn(col,_("Group"),wxLIST_FORMAT_LEFT,50);  col++;
    ListCtrlRegExResult->InsertColumn(col,_("Match result"),wxLIST_FORMAT_LEFT,740);

    m_foreColourMatch=wxColour(wxT("BLACK"));
    m_backColourMatch=wxColour(wxT("YELLOW"));

    m_foreColourFocus=wxColour(wxT("BLACK"));
    m_backColourFocus=wxColour(wxT("#BBFFFF"));

    m_foreColourSelection=wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT);
    m_backColourSelection=wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT);

    m_nStartPos=m_nEndPos=0;
    TextCtrlText->SetDefaultStyle(wxTextAttr(*wxBLACK,*wxWHITE,wxFont(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD)));
}

RegExTesterDialog::~RegExTesterDialog()
{
    //(*Destroy(RegExTesterDialog)
    //*)
}

void RegExTesterDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void RegExTesterDialog::OnAbout(wxCommandEvent& event)
{
    wxAboutDialogInfo info;
    info.SetName(wxT("Regular Expression Tester"));
    info.SetVersion(wxString::FromAscii(AutoVersion::FULLVERSION_STRING));
    info.SetCopyright(wxT("Copyright (C) 2009,2012 Liu Yugang        "));
    info.SetWebSite(wxT("liuyug@gmail.com"));
    // Don't close on wxGTK
#if 0
    wxAboutBox(info);
#else
    wxString msg;
    msg << info.GetName() << wxT("\n");
    msg << info.GetVersion() << wxT("\n");
    msg << info.GetCopyright() << wxT("\n");
    msg << info.GetWebSiteURL() << wxT("\n");
    wxMessageBox(msg, wxT("About") + info.GetName());
#endif
}

void RegExTesterDialog::OnButtonRegExMatchClick(wxCommandEvent& event)
{

    wxString strRegEx,strText,strCurText;
    strRegEx=TextCtrlRegEx->GetValue();
    strText=TextCtrlText->GetValue();

    if(TextCtrlRegEx->IsModified()) {
        TextCtrlText->SetStyle(0,TextCtrlText->GetLastPosition(),TextCtrlText->GetDefaultStyle());
        m_bNewMatch=true;
        TextCtrlRegEx->SetModified(false);
        m_nStartPos=0;
        m_nEndPos=0;
        m_RegExFlags=ChoiceRegExLib->GetSelection()|
            (CheckBoxCaseInsensitive->IsChecked()?0:wxRE_ICASE)|
            (CheckBoxMatchNewlines->IsChecked()?wxRE_NEWLINE:0);

        if(!m_regexMatch.Compile(strRegEx,m_RegExFlags)){
            wxMessageDialog msgDlg(this,_("Regular expression error!"),_("Expression error"),wxOK|wxICON_ERROR);
            msgDlg.ShowModal();
            return;
        }
        strCurText=strText;
    }
    TextCtrlText->SetStyle(m_nStartPos,m_nEndPos,wxTextAttr(m_foreColourFocus,m_backColourFocus));

    while(true){
        if(m_bNewMatch!=true)
            strCurText=strText.Mid(m_nEndPos);
        if(!m_regexMatch.Matches(strCurText)){
            if(m_bNewMatch==true){
                wxMessageDialog msgDlg(this,_("Not match"),_("match"),wxOK|wxICON_ERROR);
                msgDlg.ShowModal();
                return;
            }
            strCurText=strText;      // match from begin
            m_bNewMatch=true;
            m_nStartPos=0;
            m_nEndPos=0;
        }else
            break;
    }



    ListCtrlRegExResult->DeleteAllItems();

    int nMatchCount=m_regexMatch.GetMatchCount();
    size_t nMatchStartPos,nMatchLength,nStartPos;
    struct MATCHINFO_TAG *matchData;
    nStartPos=m_nEndPos;
    for(int i=0;i<nMatchCount;i++){
        ListCtrlRegExResult->InsertItem(i,wxString::Format(wxT("%d"),i));
        ListCtrlRegExResult->SetItem(i,1,m_regexMatch.GetMatch(strCurText,i));
        m_regexMatch.GetMatch(&nMatchStartPos,&nMatchLength,i);
        // 下一次匹配的
        if(i==0){
            m_nStartPos=nMatchStartPos+nStartPos;
            m_nEndPos=m_nStartPos+nMatchLength;
        }

        matchData=new struct MATCHINFO_TAG;
        matchData->nStartPos=nStartPos+nMatchStartPos;
        matchData->nLength=nMatchLength;
        ListCtrlRegExResult->SetItemPtrData(i,(wxUIntPtr)matchData);


    }
    ListCtrlRegExResult->SetItemState(0,wxLIST_STATE_SELECTED,wxLIST_STATE_SELECTED);
    m_bNewMatch=false;

}

void RegExTesterDialog::OnListCtrlRegExResultItemSelect(wxListEvent& event)
{
    struct MATCHINFO_TAG *matchData;
    matchData=(struct MATCHINFO_TAG *)ListCtrlRegExResult->GetItemData(event.GetIndex());

    TextCtrlText->SetStyle(matchData->nStartPos,matchData->nStartPos+matchData->nLength,wxTextAttr(m_foreColourSelection,m_backColourSelection));
    TextCtrlText->SetSelection(matchData->nStartPos,matchData->nStartPos+matchData->nLength);

}

void RegExTesterDialog::OnListCtrlRegExResultItemDeselect(wxListEvent& event)
{
    struct MATCHINFO_TAG *matchData;
    matchData=(struct MATCHINFO_TAG *)ListCtrlRegExResult->GetItemData(event.GetIndex());
    TextCtrlText->SetStyle(matchData->nStartPos,matchData->nStartPos+matchData->nLength,wxTextAttr(m_foreColourMatch,m_backColourMatch));
    TextCtrlText->SetSelection(0,0);
}

void RegExTesterDialog::OnTextCtrlTextFocusEvent(wxFocusEvent& event)
{
    if(TextCtrlText->IsEmpty()) return;
    TextCtrlText->SetStyle(m_nStartPos,m_nEndPos,wxTextAttr(m_foreColourFocus,m_backColourFocus));
    ListCtrlRegExResult->SetItemState(0,!wxLIST_STATE_SELECTED,wxLIST_STATE_SELECTED);
}

void RegExTesterDialog::OnButtonCopyAsCppClick(wxCommandEvent& event)
{
    wxString matchStr=TextCtrlRegEx->GetValue();
    matchStr.Replace(wxT("\\"),wxT("\\\\"));    /*  replace \   with \\   */
    matchStr.Replace(wxT("\""),wxT("\\\""));    /*  replace "   with \"    */
    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData( new wxTextDataObject(matchStr) );
        wxTheClipboard->Close();
    }
}
