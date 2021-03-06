/////////////////////////////////////////////////////////////////////////////
// cmdBlockWalk.cpp

#include "StdAfx.h"
#include "BlockWalkPlugIn.h"
#include "BlockWalkDialog.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN BlockWalk command
//

#pragma region BlockWalk command

class CCommandBlockWalk : public CRhinoCommand
{
public:
	CCommandBlockWalk() {}
  ~CCommandBlockWalk() {}
	UUID CommandUUID()
	{
		// {9A9B90FB-8C91-4143-90E4-8C0836140809}
    static const GUID BlockWalkCommand_UUID =
    { 0x9A9B90FB, 0x8C91, 0x4143, { 0x90, 0xE4, 0x8C, 0x8, 0x36, 0x14, 0x8, 0x9 } };
    return BlockWalkCommand_UUID;
	}
	const wchar_t* EnglishCommandName() { return L"BlockWalk"; }
	const wchar_t* LocalCommandName() const { return L"BlockWalk"; }
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};
static class CCommandBlockWalk theBlockWalkCommand;

CRhinoCommand::result CCommandBlockWalk::RunCommand( const CRhinoCommandContext& context )
{
  CRhinoInstanceDefinitionTable& idef_table = context.m_doc.m_instance_definition_table;
  if( 0 == idef_table.InstanceDefinitionCount() )
  {
    RhinoApp().Print( L"No block definitions to walk.\n" );
    return CRhinoCommand::nothing;
  }

  CBlockWalkDialog dialog( CWnd::FromHandle(RhinoApp().MainWnd()), context.m_doc );
  dialog.DoModal();

  return CRhinoCommand::success;
}

#pragma endregion

//
// END BlockWalk command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
