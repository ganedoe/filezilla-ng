#ifndef __DIRECTORYLISTINGPARSER_H__
#define __DIRECTORYLISTINGPARSER_H__

class CLine;
class CToken;
class CDirectoryListingParser
{
public:
	CDirectoryListingParser(CFileZillaEngine *pEngine);
	~CDirectoryListingParser();

	bool Parse();

	void AddData(char *pData, int len);

protected:
	CLine *GetLine();
	bool ParseLine(CLine *pLine, std::list<CDirentry> &entryList);

	bool ParseAsUnix(CLine *pLine, CDirentry &entry);
	bool ParseAsDos(CLine *pLine, CDirentry &entry);
	bool ParseAsEplf(CLine *pLine, CDirentry &entry);
	bool ParseAsVms(CLine *pLine, CDirentry &entry);
	bool ParseAsIbm(CLine *pLine, CDirentry &entry);
	bool ParseOther(CLine *pLine, CDirentry &entry);

	// Date / time parsers
	bool ParseUnixDateTime(CLine *pLine, int &index, CDirentry &entry);
	bool ParseShortDate(CToken &token, CDirentry &entry);
	bool ParseTime(CToken &token, CDirentry &entry);

	CFileZillaEngine *m_pEngine;

	std::map<wxString, int> m_MonthNamesMap;

	struct t_list
	{
		char *p;
		int len;
	};
	int startOffset;

	std::list<t_list> m_DataList;

	CLine *curLine;
	CLine *prevLine;
};

#endif
