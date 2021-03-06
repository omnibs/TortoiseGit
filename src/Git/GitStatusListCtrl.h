// TortoiseSVN - a Windows shell extension for easy version control

// Copyright (C) 2008-2011 - TortoiseGit
// Copyright (C) 2003-2008 - TortoiseSVN
// Copyright (C) 2010-2011 Sven Strickroth <email@cs-ware.de>

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once
#include "TGitPath.h"
#include "GitStatus.h"
#include "GitRev.h"
#include "GitConfig.h"
#include "Colors.h"
#include "CommonResource.h"
#include "HintListCtrl.h"

#define SVN_WC_ENTRY_WORKING_SIZE_UNKNOWN (-1)

// these defines must be in the order the columns are inserted!
#define SVNSLC_COLFILENAME			0x000000002
#define SVNSLC_COLEXT				0x000000004
#define SVNSLC_COLSTATUS			0x000000008
//#define SVNSLC_COLTEXTSTATUS		0x000000010
//#define SVNSLC_COLPROPSTATUS		0x000000020
//#define SVNSLC_COLAUTHOR			0x000000040
//#define	SVNSLC_COLREVISION			0x000000080
//#define	SVNSLC_COLDATE				0x000000100
//#define	SVNSLC_COLMODIFICATIONDATE	0x000000200
#define SVNSLC_COLADD				0x000000010
#define SVNSLC_COLDEL				0x000000020
#define SVNSLC_NUMCOLUMNS			6

//#define SVNSLC_COLREMOTESTATUS		0x000000010
//#define SVNSLC_COLREMOTETEXT		0x000000080
//#define SVNSLC_COLREMOTEPROP		0x000000100
//#define SVNSLC_COLURL				0x000000200
//#define SVNSLC_COLLOCK				0x000000400
//#define SVNSLC_COLLOCKCOMMENT		0x000000800

//#define	SVNSLC_COLREMOTEREVISION	0x000004000

//#define SVNSLC_COLSVNNEEDSLOCK		0x000010000
//#define SVNSLC_COLCOPYFROM			0x000020000

#define SVNSLC_SHOWUNVERSIONED	CTGitPath::LOGACTIONS_UNVER
#define SVNSLC_SHOWNORMAL		0x000000000
#define SVNSLC_SHOWMODIFIED		(CTGitPath::LOGACTIONS_MODIFIED)
#define SVNSLC_SHOWADDED		(CTGitPath::LOGACTIONS_ADDED|CTGitPath::LOGACTIONS_COPY)
#define SVNSLC_SHOWREMOVED		CTGitPath::LOGACTIONS_DELETED
#define SVNSLC_SHOWCONFLICTED	CTGitPath::LOGACTIONS_UNMERGED
#define SVNSLC_SHOWMISSING		0x00000000
#define SVNSLC_SHOWREPLACED		CTGitPath::LOGACTIONS_REPLACED
#define SVNSLC_SHOWMERGED		CTGitPath::LOGACTIONS_MERGED
#define SVNSLC_SHOWIGNORED		CTGitPath::LOGACTIONS_IGNORE
#define SVNSLC_SHOWOBSTRUCTED	0x00000000
#define SVNSLC_SHOWEXTERNAL		0x00000000
#define SVNSLC_SHOWINCOMPLETE	0x00000000
#define SVNSLC_SHOWINEXTERNALS	0x00000000
#define SVNSLC_SHOWREMOVEDANDPRESENT 0x00000000
#define SVNSLC_SHOWLOCKS		0x00000000
#define SVNSLC_SHOWDIRECTFILES	0x00000000
#define SVNSLC_SHOWDIRECTFOLDER 0x00000000
#define SVNSLC_SHOWEXTERNALFROMDIFFERENTREPO 0x00000000
#define SVNSLC_SHOWSWITCHED		0x00000000
#define SVNSLC_SHOWINCHANGELIST 0x00000000

#define SVNSLC_SHOWDIRECTS		(SVNSLC_SHOWDIRECTFILES | SVNSLC_SHOWDIRECTFOLDER)


#define SVNSLC_SHOWVERSIONED (CTGitPath::LOGACTIONS_FORWORD|SVNSLC_SHOWNORMAL|SVNSLC_SHOWMODIFIED|\
SVNSLC_SHOWADDED|SVNSLC_SHOWREMOVED|SVNSLC_SHOWCONFLICTED|SVNSLC_SHOWMISSING|\
SVNSLC_SHOWREPLACED|SVNSLC_SHOWMERGED|SVNSLC_SHOWIGNORED|SVNSLC_SHOWOBSTRUCTED|\
SVNSLC_SHOWEXTERNAL|SVNSLC_SHOWINCOMPLETE|SVNSLC_SHOWINEXTERNALS|\
SVNSLC_SHOWEXTERNALFROMDIFFERENTREPO)

#define SVNSLC_SHOWVERSIONEDBUTNORMAL (SVNSLC_SHOWMODIFIED|SVNSLC_SHOWADDED|\
SVNSLC_SHOWREMOVED|SVNSLC_SHOWCONFLICTED|SVNSLC_SHOWMISSING|\
SVNSLC_SHOWREPLACED|SVNSLC_SHOWMERGED|SVNSLC_SHOWIGNORED|SVNSLC_SHOWOBSTRUCTED|\
SVNSLC_SHOWEXTERNAL|SVNSLC_SHOWINCOMPLETE|SVNSLC_SHOWINEXTERNALS|\
SVNSLC_SHOWEXTERNALFROMDIFFERENTREPO)

#define SVNSLC_SHOWVERSIONEDBUTNORMALANDEXTERNALSFROMDIFFERENTREPOS (SVNSLC_SHOWMODIFIED|\
SVNSLC_SHOWADDED|SVNSLC_SHOWREMOVED|SVNSLC_SHOWCONFLICTED|SVNSLC_SHOWMISSING|\
SVNSLC_SHOWREPLACED|SVNSLC_SHOWMERGED|SVNSLC_SHOWIGNORED|SVNSLC_SHOWOBSTRUCTED|\
SVNSLC_SHOWINCOMPLETE|SVNSLC_SHOWEXTERNAL|SVNSLC_SHOWINEXTERNALS)

#define SVNSLC_SHOWVERSIONEDBUTNORMALANDEXTERNALS (SVNSLC_SHOWMODIFIED|\
	SVNSLC_SHOWADDED|SVNSLC_SHOWREMOVED|SVNSLC_SHOWCONFLICTED|SVNSLC_SHOWMISSING|\
	SVNSLC_SHOWREPLACED|SVNSLC_SHOWMERGED|SVNSLC_SHOWIGNORED|SVNSLC_SHOWOBSTRUCTED|\
	SVNSLC_SHOWINCOMPLETE)

#define SVNSLC_SHOWALL (SVNSLC_SHOWVERSIONED|SVNSLC_SHOWUNVERSIONED)

#define SVNSLC_POPALL					0xFFFFFFFFFFFFFFFF
#define SVNSLC_POPCOMPAREWITHBASE		CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_COMPARE)
#define SVNSLC_POPCOMPARE				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_COMPAREWC)
#define SVNSLC_POPGNUDIFF				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_GNUDIFF1)
#define SVNSLC_POPREVERT				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_REVERT)
#define SVNSLC_POPUPDATE				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_UPDATE)
#define SVNSLC_POPSHOWLOG				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_LOG)
#define SVNSLC_POPOPEN					CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_OPEN)
#define SVNSLC_POPDELETE				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_DELETE)
#define SVNSLC_POPADD					CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_ADD)
#define SVNSLC_POPIGNORE				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_IGNORE)
#define SVNSLC_POPCONFLICT				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_EDITCONFLICT)
#define SVNSLC_POPRESOLVE				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_RESOLVECONFLICT)
#define SVNSLC_POPLOCK					CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_LOCK)
#define SVNSLC_POPUNLOCK				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_UNLOCK)
#define SVNSLC_POPUNLOCKFORCE			CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_UNLOCKFORCE)
#define SVNSLC_POPEXPLORE				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_EXPLORE)
#define SVNSLC_POPCOMMIT				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_COMMIT)
#define SVNSLC_POPPROPERTIES			CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_PROPERTIES)
#define SVNSLC_POPREPAIRMOVE			CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_REPAIRMOVE)
#define SVNSLC_POPCHANGELISTS			CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_CHECKGROUP)
#define SVNSLC_POPBLAME					CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_BLAME)
#define SVNSLC_POPSAVEAS				CGitStatusListCtrl::GetContextMenuBit(CGitStatusListCtrl::IDSVNLC_SAVEAS)

#define SVNSLC_IGNORECHANGELIST			_T("ignore-on-commit")

// This gives up to 64 standard properties and menu entries
// plus 192 user-defined properties (should be plenty).
// User-defined properties will start at column SVNSLC_NUMCOLUMNS+1
// but in the registry, we will record them starting at SVNSLC_USERPROPCOLOFFSET.

#define SVNSLC_USERPROPCOLOFFSET        0x40
#define SVNSLC_USERPROPCOLLIMIT         0xff
#define SVNSLC_MAXCOLUMNCOUNT           0xff

// Supporting extreamly long user props makes no sense here --
// especially for binary properties. CString uses a pool allocator
// that works for up to 256 chars. Make sure we are well below that.

#define SVNSLC_MAXUSERPROPLENGTH        0x70

typedef int (__cdecl *GENERICCOMPAREFN)(const void * elem1, const void * elem2);
typedef CComCritSecLock<CComCriticalSection> Locker;

class CGitStatusListCtrlDropTarget;

/**
* \ingroup TortoiseProc
* Helper class for CGitStatusListCtrl that represents
* the columns visible and their order as well as
* persisting that data in the registry.
*
* It assigns logical index values to the (potential) columns:
* 0 .. GitSLC_NUMCOLUMNS-1 contain the standard attributes
* GitSLC_USERPROPCOLOFFSET .. GitSLC_MAXCOLUMNCOUNT are user props.
*
* The column vector contains the columns that are actually
* available in the control.
*
* Since the set of userprops may change from one WC to another,
* we also store the settings (width and order) for those
* userprops that are not used in this WC.
*
* A userprop is considered "in use", if the respective column
* is not hidden or if at least one item has this property set.
*/
class ColumnManager
{
public:

	/// construction / destruction

	ColumnManager (CListCtrl* control) : control (control) {};
	~ColumnManager() {};

	DWORD m_dwDefaultColumns;
	/// registry access

	void ReadSettings (DWORD defaultColumns, DWORD hideColumns, const CString& containerName, int ReadSettings, int *withlist=NULL);
	void WriteSettings() const;

	/// read column definitions

	int GetColumnCount() const;                     ///< total number of columns
	bool IsVisible (int column) const;
	int GetInvisibleCount() const;
	bool IsRelevant (int column) const;
	bool IsUserProp (int column) const;
	CString GetName (int column) const;
	int SetNames(UINT * buff, int size);
	int GetWidth (int column, bool useDefaults = false) const;
	int GetVisibleWidth (int column, bool useDefaults) const;

	/// switch columns on and off

	void SetVisible (int column, bool visible);

	/// tracking column modifications

	void ColumnMoved (int column, int position);
	void ColumnResized (int column);

	/// call these to update the user-prop list
	/// (will also auto-insert /-remove new list columns)

	//void UpdateUserPropList (const std::vector<FileEntry*>& files);
	//void UpdateRelevance ( const std::vector<FileEntry*>& files
	//                    , const std::vector<size_t>& visibleFiles);

	/// don't clutter the context menu with irrelevant prop info

	bool AnyUnusedProperties() const;
	void RemoveUnusedProps();

	/// bring everything back to its "natural" order

	void ResetColumns (DWORD defaultColumns);

	void OnColumnResized(NMHDR *pNMHDR, LRESULT *pResult)
	{
		LPNMHEADER header = reinterpret_cast<LPNMHEADER>(pNMHDR);
		if (   (header != NULL)
			&& (header->iItem >= 0)
			&& (header->iItem < GetColumnCount()))
		{
			ColumnResized (header->iItem);
		}
		*pResult = 0;
	}

	void OnColumnMoved(NMHDR *pNMHDR, LRESULT *pResult)
	{
		LPNMHEADER header = reinterpret_cast<LPNMHEADER>(pNMHDR);
		*pResult = TRUE;
		if (   (header != NULL)
			&& (header->iItem >= 0)
			&& (header->iItem < GetColumnCount())
			// only allow the reordering if the column was not moved left of the first
			// visible item - otherwise the 'invisible' columns are not at the far left
			// anymore and we get all kinds of redrawing problems.
			&& (header->pitem)
			&& (header->pitem->iOrder > GetInvisibleCount()))
		{
			ColumnMoved (header->iItem, header->pitem->iOrder);
			*pResult = FALSE;
		}
	}

	void OnHdnBegintrack(NMHDR *pNMHDR, LRESULT *pResult)
	{
		LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
		*pResult = 0;
		if ((phdr->iItem < 0)||(phdr->iItem >= itemName.size()))
			return;

		if (IsVisible (phdr->iItem))
		{
			return;
		}
		*pResult = 1;
	}

	int OnHdnItemchanging(NMHDR *pNMHDR, LRESULT *pResult)
	{
		LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
		*pResult = 0;
		if ((phdr->iItem < 0)||(phdr->iItem >= itemName.size()))
		{
			return 0;
		}

		// visible columns may be modified

		if (IsVisible (phdr->iItem))
		{
			return 0;
		}

		// columns already marked as "invisible" internally may be (re-)sized to 0

		if (   (phdr->pitem != NULL)
			&& (phdr->pitem->mask == HDI_WIDTH)
			&& (phdr->pitem->cxy == 0))
		{
			return 0;
		}

		if (   (phdr->pitem != NULL)
			&& (phdr->pitem->mask != HDI_WIDTH))
		{
			return 0;
		}

		*pResult = 1;
		return 1;
	}
	void OnContextMenuHeader(CWnd * pWnd, CPoint point, bool isGroundEnable=false)
	{
		bool XPorLater = false;
		OSVERSIONINFOEX inf;
		SecureZeroMemory(&inf, sizeof(OSVERSIONINFOEX));
		inf.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
		GetVersionEx((OSVERSIONINFO *)&inf);
		WORD fullver = MAKEWORD(inf.dwMinorVersion, inf.dwMajorVersion);
		if (fullver >= 0x0501)
			XPorLater = true;

		CHeaderCtrl * pHeaderCtrl = (CHeaderCtrl *)pWnd;
		if ((point.x == -1) && (point.y == -1))
		{
			CRect rect;
			pHeaderCtrl->GetItemRect(0, &rect);
			pHeaderCtrl->ClientToScreen(&rect);
			point = rect.CenterPoint();
		}

		CMenu popup;
		if (popup.CreatePopupMenu())
		{
			int columnCount = GetColumnCount();

			CString temp;
			UINT uCheckedFlags = MF_STRING | MF_ENABLED | MF_CHECKED;
			UINT uUnCheckedFlags = MF_STRING | MF_ENABLED;

			// build control menu

			if (XPorLater)
			{
				//temp.LoadString(IDS_STATUSLIST_SHOWGROUPS);
				//popup.AppendMenu(isGroundEnable? uCheckedFlags : uUnCheckedFlags, columnCount, temp);
			}

			if (AnyUnusedProperties())
			{
				temp.LoadString(IDS_STATUSLIST_REMOVEUNUSEDPROPS);
				popup.AppendMenu(uUnCheckedFlags, columnCount+1, temp);
			}

			temp.LoadString(IDS_STATUSLIST_RESETCOLUMNORDER);
			popup.AppendMenu(uUnCheckedFlags, columnCount+2, temp);
			popup.AppendMenu(MF_SEPARATOR);

			// standard columns
			AddMenuItem(&popup);

			// user-prop columns:
			// find relevant ones and sort 'em

			std::map<CString, int> sortedProps;
			for (int i = itemName.size(); i < columnCount; ++i)
			if (IsRelevant(i))
				sortedProps[GetName(i)] = i;

			if (!sortedProps.empty())
			{
				// add 'em to the menu

				popup.AppendMenu(MF_SEPARATOR);

				typedef std::map<CString, int>::const_iterator CIT;
				for ( CIT iter = sortedProps.begin(), end = sortedProps.end()
					; iter != end
					; ++iter)
				{
					popup.AppendMenu ( IsVisible(iter->second)
						? uCheckedFlags
						: uUnCheckedFlags
						, iter->second
						, iter->first);
				}
			}

			// show menu & let user pick an entry

			int cmd = popup.TrackPopupMenu(TPM_RETURNCMD | TPM_LEFTALIGN | TPM_NONOTIFY, point.x, point.y, pWnd, 0);
			if ((cmd >= 1)&&(cmd < columnCount))
			{
				SetVisible (cmd, !IsVisible(cmd));
			}
			else if (cmd == columnCount)
			{
				pWnd->GetParent()->SendMessage(LVM_ENABLEGROUPVIEW, !isGroundEnable, NULL);
				//EnableGroupView(!isGroundEnable);
			}
			else if (cmd == columnCount+1)
			{
				RemoveUnusedProps();
			}
			else if (cmd == columnCount+2)
			{
				ResetColumns (m_dwDefaultColumns);
			}
		}
	}

	void AddMenuItem(CMenu *pop)
	{
		UINT uCheckedFlags = MF_STRING | MF_ENABLED | MF_CHECKED;
		UINT uUnCheckedFlags = MF_STRING | MF_ENABLED;

		for (int i = 1; i < itemName.size(); ++i)
		{
			if(IsRelevant(i))
				pop->AppendMenu ( IsVisible(i)
					? uCheckedFlags
					: uUnCheckedFlags
					, i
					, GetName(i));
		}
	}
private:

	/// initialization utilities

	void ParseUserPropSettings ( const CString& userPropList
		, const CString& shownUserProps);
	void ParseWidths (const CString& widths);
	void SetStandardColumnVisibility (DWORD visibility);
	void ParseColumnOrder (const CString& widths);

	/// map internal column order onto visible column order
	/// (all invisibles in front)

	std::vector<int> GetGridColumnOrder();
	void ApplyColumnOrder();

	/// utilities used when writing data to the registry

	DWORD GetSelectedStandardColumns() const;
	CString GetUserPropList() const;
	CString GetShownUserProps() const;
	CString GetWidthString() const;
	CString GetColumnOrderString() const;

	/// our parent control and its data

	CListCtrl* control;

	/// where to store in the registry

	CString registryPrefix;

	/// all columns in their "natural" order

	struct ColumnInfo
	{
		int index;          ///< is a user prop when < GitSLC_USERPROPCOLOFFSET
		int width;
		bool visible;
		bool relevant;      ///< set to @a visible, if no *shown* item has that property
	};

	std::vector<ColumnInfo> columns;

	/// user-defined properties

	struct UserProp
	{
		CString name;       ///< is a user prop when < GitSLC_USERPROPCOLOFFSET
		int width;
	};

	std::vector<UserProp> userProps;

	/// stored result from last UpdateUserPropList() call

	std::set<CString> itemProps;

	/// global column ordering including unused user props

	std::vector<int> columnOrder;

	std::vector<int> itemName;

};

/**
* \ingroup TortoiseProc
* Simple utility class that defines the sort column order.
*/
class CSorter
{
public:

	CSorter ( ColumnManager* columnManager
		, int sortedColumn
		, bool ascending);

	bool operator() ( const CTGitPath* entry1
		, const CTGitPath* entry2) const;

	static int A2L(const CString &str)
	{
		if(str==_T("-"))
			return -1;
		else
			return _ttol(str);
	}

private:

	ColumnManager* columnManager;
	int sortedColumn;
	bool ascending;
};

/**
 * \ingroup SVN
 * A List control, based on the MFC CListCtrl which shows a list of
 * files with their Subversion status. The control also provides a context
 * menu to do some Subversion tasks on the selected files.
 *
 * This is the main control used in many dialogs to show a list of files to
 * work on.
 */
class CGitStatusListCtrl :
	public CListCtrl
{
public:
	enum
	{
		IDSVNLC_REVERT = 1,
		IDSVNLC_COMPARE,
		IDSVNLC_OPEN,
		IDSVNLC_DELETE,
		IDSVNLC_IGNORE,
		IDSVNLC_GNUDIFF1		 ,
		IDSVNLC_UPDATE          ,
		IDSVNLC_LOG              ,
		IDSVNLC_EDITCONFLICT     ,
		IDSVNLC_IGNOREMASK	    ,
		IDSVNLC_ADD			    ,
		IDSVNLC_RESOLVECONFLICT ,
		IDSVNLC_LOCK			,
		IDSVNLC_LOCKFORCE		,
		IDSVNLC_UNLOCK			,
		IDSVNLC_UNLOCKFORCE		,
		IDSVNLC_OPENWITH		,
		IDSVNLC_EXPLORE			,
		IDSVNLC_RESOLVETHEIRS	,
		IDSVNLC_RESOLVEMINE		,
		IDSVNLC_REMOVE			,
		IDSVNLC_COMMIT			,
		IDSVNLC_PROPERTIES		,
		IDSVNLC_COPY			,
		IDSVNLC_COPYEXT			,
		IDSVNLC_REPAIRMOVE		,
		IDSVNLC_REMOVEFROMCS	,
		IDSVNLC_CREATECS		,
		IDSVNLC_CREATEIGNORECS	,
		IDSVNLC_CHECKGROUP		,
		IDSVNLC_UNCHECKGROUP	,
		IDSVNLC_ADD_RECURSIVE   ,
		IDSVNLC_COMPAREWC		,
		IDSVNLC_BLAME			,
		IDSVNLC_SAVEAS			,
		IDSVNLC_REVERTTOREV		,
		IDSVNLC_VIEWREV			,
		IDSVNLC_FINDENTRY       ,
		IDSVNLC_COMPARETWO		,
		IDSVNLC_GNUDIFF2		,
// the IDSVNLC_MOVETOCS *must* be the last index, because it contains a dynamic submenu where
// the submenu items get command ID's sequent to this number
		IDSVNLC_MOVETOCS		,
	};
	int GetColumnIndex(int colmask);
	static inline unsigned __int64 GetContextMenuBit(int i){ return ((unsigned __int64 )0x1)<<i ;}
	/**
	 * Sent to the parent window (using ::SendMessage) after a context menu
	 * command has finished if the item count has changed.
	 */
	static const UINT SVNSLNM_ITEMCOUNTCHANGED;
	/**
	 * Sent to the parent window (using ::SendMessage) when the control needs
	 * to be refreshed. Since this is done usually in the parent window using
	 * a thread, this message is used to tell the parent to do exactly that.
	 */
	static const UINT SVNSLNM_NEEDSREFRESH;

	/**
	 * Sent to the parent window (using ::SendMessage) when the user drops
	 * files on the control. The LPARAM is a pointer to a TCHAR string
	 * containing the dropped path.
	 */
	static const UINT SVNSLNM_ADDFILE;

	/**
	 * Sent to the parent window (using ::SendMessage) when the user checks/unchecks
	 * one or more items in the control. The WPARAM contains the number of
	 * checked items in the control.
	 */
	static const UINT SVNSLNM_CHECKCHANGED;

	static const UINT SVNSLNM_ITEMCHANGED;

	CGitStatusListCtrl(void);
	~CGitStatusListCtrl(void);

	CString m_Rev1;
	CString m_Rev2;

	/**
	 * \ingroup TortoiseProc
	 * Helper class for CGitStatusListCtrl which represents
	 * the data for each file shown.
	 */
#if 0
	class FileEntry
	{
	public:
		FileEntry() : status(git_wc_status_unversioned)
//			, copyfrom_rev(GIT_REV_ZERO)
			, last_commit_date(0)
			, last_commit_rev(GIT_REV_ZERO)
//			, remoterev(GIT_REV_ZERO)
			, textstatus(git_wc_status_unversioned)
			, propstatus(git_wc_status_unversioned)
//			, remotestatus(git_wc_status_unversioned)
//			, remotetextstatus(git_wc_status_unversioned)
//			, remotepropstatus(git_wc_status_unversioned)
			, copied(false)
			, switched(false)
			, checked(false)
			, inunversionedfolder(false)
			, inexternal(false)
			, differentrepo(false)
			, direct(false)
			, isfolder(false)
			, isNested(false)
			, Revision(GIT_REV_ZERO)
			, isConflicted(false)
//			, present_props()
			, needslock(false)
///			, working_size(SVN_WC_ENTRY_WORKING_SIZE_UNKNOWN)
			, keeplocal(false)
//			, depth(git_depth_unknown)
		{
		}
		const CTGitPath& GetPath() const
		{
			return path;
		}
		const bool IsChecked() const
		{
			return checked;
		}
		CString GetRelativeGitPath() const
		{
			if (path.IsEquivalentTo(basepath))
				return path.GetGitPathString();
			return path.GetGitPathString().Mid(basepath.GetGitPathString().GetLength()+1);
		}
//		const bool IsLocked() const
//		{
//			return !(lock_token.IsEmpty() && lock_remotetoken.IsEmpty());
//		}
//		const bool HasNeedsLock() const
//		{
//			return needslock;
//		}
		const bool IsFolder() const
		{
			return isfolder;
		}
		const bool IsInExternal() const
		{
			return inexternal;
		}
		const bool IsNested() const
		{
			return isNested;
		}
		const bool IsFromDifferentRepository() const
		{
			return differentrepo;
		}
		CString GetDisplayName() const
		{
			CString const& chopped = path.GetDisplayString(&basepath);
			if (!chopped.IsEmpty())
			{
				return chopped;
			}
			else
			{
				// "Display name" must not be empty.
				return path.GetFileOrDirectoryName();
			}
		}
		CString GetChangeList() const
		{
			return changelist;
		}
//		CString GetURL() const
//		{
//			return url;
//		}
	public:
		git_wc_status_kind		status;					///< local status
		git_wc_status_kind		textstatus;				///< local text status
		git_wc_status_kind		propstatus;				///< local property status

	private:
		CTGitPath				path;					///< full path of the file
		CTGitPath				basepath;				///< common ancestor path of all files

		CString					changelist;				///< the name of the changelist the item belongs to

		CString					last_commit_author;		///< the author which last committed this item
		CTime					last_commit_date;		///< the date when this item was last committed
		git_revnum_t			last_commit_rev;		///< the revision where this item was last committed

		git_revnum_t			remoterev;				///< the revision in HEAD of the repository
		bool					copied;					///< if the file/folder is added-with-history
		bool					switched;				///< if the file/folder is switched to another url
		bool					checked;				///< if the file is checked in the list control
		bool					inunversionedfolder;	///< if the file is inside an unversioned folder
		bool					inexternal;				///< if the item is in an external folder
		bool					differentrepo;			///< if the item is from a different repository than the rest
		bool					direct;					///< directly included (TRUE) or just a child of a folder
		bool					isfolder;				///< TRUE if entry refers to a folder
		bool					isNested;				///< TRUE if the folder from a different repository and/or path
		bool					isConflicted;			///< TRUE if a file entry is conflicted, i.e. if it has the conflicted paths set
		bool					needslock;				///< TRUE if the Git:needs-lock property is set
		git_revnum_t			Revision;				///< the base revision
//		PropertyList			present_props;			///< cacheable properties present in BASE
		bool					keeplocal;				///< Whether a local copy of this entry should be kept in the working copy after a deletion has been committed
		git_depth_t				depth;					///< the depth of this entry
		friend class CGitStatusListCtrl;
		friend class CGitStatusListCtrlDropTarget;
        friend class CSorter;
	};
#endif

	/**
	 * Initializes the control, sets up the columns.
	 * \param dwColumns mask of columns to show. Use the GitSLC_COLxxx defines.
	 * \param sColumnInfoContainer Name of a registry key
	 *                             where the position and visibility of each column
	 *                             is saved and used from. If the registry key
	 *                             doesn't exist, the default order is used
	 *                             and dwColumns tells which columns are visible.
	 * \param dwContextMenus mask of context menus to be active, not all make sense for every use of this control.
	 *                       Use the GitSLC_POPxxx defines.
	 * \param bHasCheckboxes TRUE if the control should show check boxes on the left of each file entry.
	 */
	void Init(DWORD dwColumns, const CString& sColumnInfoContainer, unsigned __int64 dwContextMenus = (SVNSLC_POPALL ^ SVNSLC_POPCOMMIT), bool bHasCheckboxes = true);
	/**
	 * Sets a background image for the list control.
	 * The image is shown in the right bottom corner.
	 * \param nID the resource ID of the bitmap to use as the background
	 */
	bool SetBackgroundImage(UINT nID);
	/**
	 * Makes the 'ignore' context menu only ignore the files and not add the
	 * folder which gets the Git:ignore property changed to the list.
	 * This is needed e.g. for the Add-dialog, where the modified folder
	 * showing up would break the resulting "add" command.
	 */
	void SetIgnoreRemoveOnly(bool bRemoveOnly = true) {m_bIgnoreRemoveOnly = bRemoveOnly;}
	/**
	 * The unversioned items are by default shown after all other files in the list.
	 * If that behavior should be changed, set this value to false.
	 */
	void PutUnversionedLast(bool bLast) {m_bUnversionedLast = bLast;}
	/**
	 * Fetches the Subversion status of all files and stores the information
	 * about them in an internal array.
	 * \param sFilePath path to a file which contains a list of files and/or folders for which to
	 *                  fetch the status, separated by newlines.
	 * \param bUpdate TRUE if the remote status is requested too.
	 * \return TRUE on success.
	 */
	BOOL GetStatus ( const CTGitPathList* pathList=NULL
                   , bool bUpdate = false
                   , bool bShowIgnores = false
				   , bool bShowUnRev=false
                   , bool bShowUserProps = false);

	/**
	 * Populates the list control with the previously (with GetStatus) gathered status information.
	 * \param dwShow mask of file types to show. Use the GitSLC_SHOWxxx defines.
	 * \param dwCheck mask of file types to check. Use GitLC_SHOWxxx defines. Default (0) means 'use the entry's stored check status'
	 */
	void Show(unsigned int dwShow, unsigned int dwCheck = 0, bool bShowFolders = true,BOOL updateStatusList=FALSE, bool UseStoredCheckStatus=false);
	void Show(unsigned int dwShow, const CTGitPathList& checkedList, bool bShowFolders = true);

	/**
	 * Copies the selected entries in the control to the clipboard. The entries
	 * are separated by newlines.
	 * \param dwCols the columns to copy. Each column is separated by a tab.
	 */
	bool CopySelectedEntriesToClipboard(DWORD dwCols);

	/**
	 * If during the call to GetStatus() some Git:externals are found from different
	 * repositories than the first one checked, then this method returns TRUE.
	 */
	BOOL HasExternalsFromDifferentRepos() const {return m_bHasExternalsFromDifferentRepos;}

	/**
	 * If during the call to GetStatus() some Git:externals are found then this method returns TRUE.
	 */
	BOOL HasExternals() const {return m_bHasExternals;}

	/**
	 * If unversioned files are found (but not necessarily shown) TRUE is returned.
	 */
	BOOL HasUnversionedItems() {return m_bHasUnversionedItems;}

	/**
	 * If there are any locks in the working copy, TRUE is returned
	 */
	BOOL HasLocks() const {return m_bHasLocks;}

	/**
	 * If there are any change lists defined in the working copy, TRUE is returned
	 */
	BOOL HasChangeLists() const {return m_bHasChangeLists;}

	/**
	 * Returns the file entry data for the list control index.
	 */
	//CGitStatusListCtrl::FileEntry * GetListEntry(UINT_PTR index);

	/**
	 * Returns the file entry data for the specified path.
	 * \note The entry might not be shown in the list control.
	 */
	//CGitStatusListCtrl::FileEntry * GetListEntry(const CTGitPath& path);

	/**
	 * Returns the index of the list control entry with the specified path,
	 * or -1 if the path is not in the list control.
	 */
	int GetIndex(const CTGitPath& path);

	/**
	 * Returns the file entry data for the specified path in the list control.
	 */
	//CGitStatusListCtrl::FileEntry * GetVisibleListEntry(const CTGitPath& path);

	/**
	 * Returns a String containing some statistics like number of modified, normal, deleted,...
	 * files.
	 */
	CString GetStatisticsString(bool simple=false);

	/**
	 * Set a static control which will be updated automatically with
	 * the number of selected and total files shown in the list control.
	 */
	void SetStatLabel(CWnd * pStatLabel){m_pStatLabel = pStatLabel;};

	/**
	 * Set a tri-state checkbox which is updated automatically if the
	 * user checks/unchecks file entries in the list control to indicate
	 * if all files are checked, none are checked or some are checked.
	 */
	void SetSelectButton(CButton * pButton) {m_pSelectButton = pButton;}

	/**
	 * Set a button which is de-/activated automatically. The button is
	 * only set active if at least one item is selected.
	 */
	void SetConfirmButton(CButton * pButton) {m_pConfirmButton = pButton;}

	/**
	 * Select/unselect all entries in the list control.
	 * \param bSelect TRUE to check, FALSE to uncheck.
	 */
	void SelectAll(bool bSelect, bool bIncludeNoCommits = false);

	/** Set a checkbox on an entry in the listbox
	 * Keeps the listctrl checked state and the FileEntry's checked flag in sync
	 */
	void SetEntryCheck(CTGitPath* pEntry, int listboxIndex, bool bCheck);

	/** Write a list of the checked items' paths into a path list
	 */
	void WriteCheckedNamesToPathList(CTGitPathList& pathList);

	/** fills in \a lMin and \a lMax with the lowest/highest revision of all
	 * files/folders in the working copy.
	 * \param bShownOnly if true, the min/max revisions are calculated only for shown items
	 * \param bCheckedOnly if true, the min/max revisions are calculated only for items
	 *                   which are checked.
	 * \remark Since an item can only be checked if it is visible/shown in the list control
	 *         bShownOnly is automatically set to true if bCheckedOnly is true
	 */
	void GetMinMaxRevisions(git_revnum_t& rMin, git_revnum_t& rMax, bool bShownOnly, bool bCheckedOnly);

	/**
	 * Returns the parent directory of all entries in the control.
	 * if \a bStrict is set to false, then the paths passed to the control
	 * to fetch the status (in GetStatus()) are used if possible.
	 */
	CString GetCommonDirectory(bool bStrict);

	/**
	 * Returns the parent url of all entries in the control.
	 * if \a bStrict is set to false, then the paths passed to the control
	 * to fetch the status (in GetStatus()) are used if possible.
	 */
	CTGitPath GetCommonURL(bool bStrict);

	/**
	 * Sets a pointer to a boolean variable which is checked periodically
	 * during the status fetching. As soon as the variable changes to true,
	 * the operations stops.
	 */
	void SetCancelBool(bool * pbCanceled) {m_pbCanceled = pbCanceled;}

	/**
	 * Sets the string shown in the control while the status is fetched.
	 * If not set, it defaults to "please wait..."
	 */
	void SetBusyString(const CString& str) {m_sBusy = str;}
	void SetBusyString(UINT id) {m_sBusy.LoadString(id);}

	/**
	 * Sets the string shown in the control if no items are shown. This
	 * can happen for example if there's nothing modified and the unversioned
	 * files aren't shown either, so there's nothing to commit.
	 * If not set, it defaults to "file list is empty".
	 */
	void SetEmptyString(const CString& str) {m_sEmpty = str;}
	void SetEmptyString(UINT id) {m_sEmpty.LoadString(id);}

	/**
	 * Determines if the control should recurse into unversioned folders
	 * when fetching the status. The default behavior is defined by the
	 * registry key HKCU\Software\TortoiseGit\UnversionedRecurse, which
	 * is read in the Init() method.
	 * If you want to change the behavior, call this method *after*
	 * calling Init().
	 */
	void SetUnversionedRecurse(bool bUnversionedRecurse) {m_bUnversionedRecurse = bUnversionedRecurse;}

	/**
	 * Returns the number of selected items
	 */
	LONG GetSelected(){return m_nSelected;};

	/**
	 * Enables dropping of files on the control.
	 */
	bool EnableFileDrop();

	/**
	 * Checks if the path already exists in the list.
	 */
	bool HasPath(const CTGitPath& path);
	/**
	 * Checks if the path is shown/visible in the list control.
	 */
	bool IsPathShown(const CTGitPath& path);
	/**
	 * Forces the children to be checked when the parent folder is checked,
	 * and the parent folder to be unchecked if one of its children is unchecked.
	 */
	void CheckChildrenWithParent(bool bCheck) {m_bCheckChildrenWithParent = bCheck;}

	/**
	 * Allows checking the items if change lists are present. If set to false,
	 * items are not checked if at least one changelist is available.
	 */
	void CheckIfChangelistsArePresent(bool bCheck) {m_bCheckIfGroupsExist = bCheck;}
	/**
	 * Returns the currently used show flags passed to the Show() method.
	 */
	DWORD GetShowFlags() {return m_dwShow;}
public:
	CString GetLastErrorMessage() {return m_sLastError;}

	void Block(BOOL block, BOOL blockUI) {m_bBlock = block; m_bBlockUI = blockUI;}

	LONG						m_nTargetCount;		///< number of targets in the file passed to GetStatus()

	CString						m_sURL;				///< the URL of the target or "(multiple targets)"

	GitRev						m_HeadRev;			///< the HEAD revision of the repository if bUpdate was TRUE

	bool						m_amend;			///< if true show the changes to the revision before the last commit

	CString						m_sUUID;			///< the UUID of the associated repository

	bool						m_bIsRevertTheirMy;	///< at rebase case, Their and My version is revert.

	DECLARE_MESSAGE_MAP()

public:
	void SetBusy(bool b) {m_bBusy = b; Invalidate();}

private:
	void SaveColumnWidths(bool bSaveToRegistry = false);
	//void AddEntry(FileEntry * entry, WORD langID, int listIndex);	///< add an entry to the control
	void RemoveListEntry(int index);	///< removes an entry from the listcontrol and both arrays
	bool BuildStatistics();	///< build the statistics and correct the case of files/folders
	void StartDiff(int fileindex);	///< start the external diff program
	void StartDiffWC(int fileindex);	///< start the external diff program
	void StartDiffTwo(int fileindex);

	enum
	{
		ALTERNATIVEEDITOR,
		OPEN,
		OPEN_WITH,
	};
	void OpenFile(CTGitPath *path,int mode);

    /// fetch all user properties for all items
    void FetchUserProperties();

	/// Process one line of the command file supplied to GetStatus
	bool FetchStatusForSingleTarget(GitConfig& config, GitStatus& status, const CTGitPath& target,
		bool bFetchStatusFromRepository, CStringA& strCurrentRepositoryUUID, CTGitPathList& arExtPaths,
		bool bAllDirect, git_depth_t depth = git_depth_infinity, bool bShowIgnores = false);

	/// Create 'status' data for each item in an unversioned folder
	void AddUnversionedFolder(const CTGitPath& strFolderName, const CTGitPath& strBasePath, GitConfig * config);

	/// Read the all the other status items which result from a single GetFirstStatus call
	void ReadRemainingItemsStatus(GitStatus& status, const CTGitPath& strBasePath, CStringA& strCurrentRepositoryUUID, CTGitPathList& arExtPaths, GitConfig * config, bool bAllDirect);

	/// Clear the status vector (contains custodial pointers)
	void ClearStatusArray();

	/// Sort predicate function - Compare the paths of two entries without regard to case
	//static bool EntryPathCompareNoCase(const FileEntry* pEntry1, const FileEntry* pEntry2);

	/// Predicate used to build a list of only the versioned entries of the FileEntry array
	//static bool IsEntryVersioned(const FileEntry* pEntry1);

	/// Look up the relevant show flags for a particular Git status value
	DWORD GetShowFlagsFromGitStatus(git_wc_status_kind status);

	/// Build a FileEntry item and add it to the FileEntry array
	//const FileEntry* AddNewFileEntry(
	//	const git_wc_status2_t* pGitStatus,  // The return from the Git GetStatus functions
	//	const CTGitPath& path,				// The path of the item we're adding
	//	const CTGitPath& basePath,			// The base directory for this status build
	//	bool bDirectItem,					// Was this item the first found by GetFirstFileStatus or by a subsequent GetNextFileStatus call
	//	bool bInExternal,					// Are we in an 'external' folder
	//	bool bEntryfromDifferentRepo		// if the entry is from a different repository
	//	);

	/// Adjust the checkbox-state on all descendants of a specific item
	//void SetCheckOnAllDescendentsOf(const FileEntry* parentEntry, bool bCheck);

	/// Build a path list of all the selected items in the list (NOTE - SELECTED, not CHECKED)
	void FillListOfSelectedItemPaths(CTGitPathList& pathList, bool bNoIgnored = false);

	/// Enables/Disables group view and adds all groups to the list control.
	/// If bForce is true, then group view is enabled and the 'null' group is added.
	bool PrepareGroups(bool bForce = false);
	/// Returns the group number to which the group header belongs
	/// If the point is not over a group header, -1 is returned
	int GetGroupFromPoint(POINT * ppt);
	/// Returns the number of change lists the selection has
	size_t GetNumberOfChangelistsInSelection();

	/// Puts the item to the corresponding group
	bool SetItemGroup(int item, int groupindex);

	void CheckEntry(int index, int nListItems);
	void UncheckEntry(int index, int nListItems);

	/// sends an GitSLNM_CHECKCHANGED notification to the parent
	void NotifyCheck();

	int CellRectFromPoint(CPoint& point, RECT *cellrect, int *col) const;

	void OnContextMenuList(CWnd * pWnd, CPoint point);
	void OnContextMenuGroup(CWnd * pWnd, CPoint point);
	void OnContextMenuHeader(CWnd * pWnd, CPoint point);

	virtual void PreSubclassWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
	afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnToolTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchanging(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg BOOL OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnColumnResized(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnColumnMoved(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	void CreateChangeList(const CString& name);

	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnGetInfoTip(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnNMReturn(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
	afx_msg void OnHdnBegintrack(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemchanging(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();


	void FileSaveAs(CTGitPath *path);
	int RevertSelectedItemToVersion();

private:
	bool *						m_pbCanceled;
	bool					    m_bAscending;		///< sort direction
	int					        m_nSortedColumn;	///< which column to sort
	bool						m_bHasCheckboxes;
	bool						m_bUnversionedLast;
	bool						m_bHasExternalsFromDifferentRepos;
	bool						m_bHasExternals;
	BOOL						m_bHasUnversionedItems;
	bool						m_bHasLocks;
	bool						m_bHasChangeLists;
	//typedef std::vector<FileEntry*> FileEntryVector;
	//FileEntryVector				m_arStatusArray;
	std::vector<CTGitPath*>		m_arStatusArray;
	std::vector<size_t>			m_arListArray;
	std::map<CString, int>	    m_changelists;
	bool						m_bHasIgnoreGroup;
	//CTGitPathList				m_ConflictFileList;
	CTGitPathList				m_StatusFileList;
	CTGitPathList				m_UnRevFileList;
	CTGitPathList				m_IgnoreFileList;
	//CTGitPathList				m_StatusUrlList;
	CString						m_sLastError;

	LONG						m_nUnversioned;
	LONG						m_nNormal;
	LONG						m_nModified;
	LONG						m_nAdded;
	LONG						m_nDeleted;
	LONG						m_nConflicted;
	LONG						m_nTotal;
	LONG						m_nSelected;
	LONG						m_nLineAdded;
	LONG						m_nLineDeleted;
	LONG						m_nRenamed;

	DWORD						m_dwDefaultColumns;
	DWORD						m_dwShow;
	bool						m_bShowFolders;
	bool						m_bShowIgnores;
	bool						m_bUpdate;
	unsigned __int64			m_dwContextMenus;
	BOOL						m_bBlock;
	BOOL						m_bBlockUI;
	bool						m_bBusy;
	bool						m_bEmpty;
	bool						m_bIgnoreRemoveOnly;
	bool						m_bCheckIfGroupsExist;
	bool						m_bFileDropsEnabled;
	bool						m_bOwnDrag;

	int							m_nIconFolder;

	CWnd *						m_pStatLabel;
	CButton *					m_pSelectButton;
	CButton *					m_pConfirmButton;
	CColors						m_Colors;

	CString						m_sEmpty;
	CString						m_sBusy;
	CString						m_sNoPropValueText;

	bool						m_bUnversionedRecurse;

	bool						m_bCheckChildrenWithParent;
	CGitStatusListCtrlDropTarget * m_pDropTarget;

    ColumnManager               m_ColumnManager;

	std::map<CString,bool>		m_mapFilenameToChecked; ///< Remember manually de-/selected items
	CComCriticalSection			m_critSec;

	friend class CGitStatusListCtrlDropTarget;
public:
	enum
	{
		FILELIST_MODIFY= 0x1,
		FILELIST_UNVER = 0x2,
		FILELIST_IGNORE =0x4
	};
public:
	int UpdateFileList(git_revnum_t hash,CTGitPathList *List=NULL);
	int UpdateFileList(int mask, bool once=true,CTGitPathList *List=NULL);
	int UpdateUnRevFileList(CTGitPathList *List=NULL);
	int UpdateIgnoreFileList(CTGitPathList *List=NULL);

	int UpdateWithGitPathList(CTGitPathList &list);

	void AddEntry(CTGitPath* path, WORD langID, int ListIndex);
	void Clear();
	int m_FileLoaded;
	git_revnum_t m_CurrentVersion;
	bool m_bDoNotAutoselectSubmodules;
};

#if 0
class CGitStatusListCtrlDropTarget : public CIDropTarget
{
public:
	CGitStatusListCtrlDropTarget(CGitStatusListCtrl * pGitStatusListCtrl):CIDropTarget(pGitStatusListCtrl->m_hWnd){m_pGitStatusListCtrl = pGitStatusListCtrl;}

	virtual bool OnDrop(FORMATETC* pFmtEtc, STGMEDIUM& medium, DWORD * /*pdwEffect*/, POINTL pt);
	virtual HRESULT STDMETHODCALLTYPE DragOver(DWORD grfKeyState, POINTL pt, DWORD __RPC_FAR *pdwEffect);
private:
	CGitStatusListCtrl * m_pGitStatusListCtrl;
};
#endif
