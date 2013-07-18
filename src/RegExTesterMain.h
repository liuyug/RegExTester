/***************************************************************
 * Name:      RegExTesterMain.h
 * Purpose:   Defines Application Frame
 * Author:    Liu Yu Gang ()
 * Created:   2008-08-29
 * Copyright: Liu Yu Gang ()
 * License:
 **************************************************************/

#ifndef REGEXTESTERMAIN_H
#define REGEXTESTERMAIN_H

//(*Headers(RegExTesterDialog)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include <wx/regex.h>

class RegExTesterDialog: public wxDialog
{

    public:

        RegExTesterDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~RegExTesterDialog();

    private:
        struct MATCHINFO_TAG{
            int nStartPos;
            int nLength;
        };

        //(*Handlers(RegExTesterDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButtonRegExMatchClick(wxCommandEvent& event);
        void OnListCtrlRegExResultItemSelect(wxListEvent& event);
        void OnListCtrlRegExResultItemDeselect(wxListEvent& event);
        void OnButtonCopyAsCppClick(wxCommandEvent& event);
        //*)
        void OnTextCtrlTextFocusEvent(wxFocusEvent& event);


        //(*Identifiers(RegExTesterDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        static const long ID_LISTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(RegExTesterDialog)
        wxTextCtrl* TextCtrlRegEx;
        wxButton* ButtonCopyAsCpp;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxListCtrl* ListCtrlRegExResult;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxTextCtrl* TextCtrlText;
        wxStaticText* StaticText3;
        wxCheckBox* CheckBoxMatchNewlines;
        wxButton* Button2;
        wxCheckBox* CheckBoxCaseInsensitive;
        wxBoxSizer* BoxSizer1;
        wxButton* ButtonRegExMatch;
        wxChoice* ChoiceRegExLib;
        //*)

        int m_RegExFlags;
        int m_nStartPos;
        int m_nEndPos;

        bool     m_bNewMatch;
        wxRegEx  m_regexMatch;
        wxColour m_foreColourMatch;
        wxColour m_backColourMatch;
        wxColour m_foreColourSelection;
        wxColour m_backColourSelection;
        wxColour m_foreColourFocus;
        wxColour m_backColourFocus;

        DECLARE_EVENT_TABLE()
};

#endif // REGEXTESTERMAIN_H
