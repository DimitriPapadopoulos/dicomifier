
#ifndef BRUKERDATASET_H
#define BRUKERDATASET_H
/*! \file BrukerDataset.h
*/

#include <string>
#include <fstream>

#include "BrukerSystem.h"
#include "BrukerFieldData.h"
    
/*! \class  BrukerDataset
    \brief This class purpose is to extract information from a bruker experiment and setup the extracted information for an easy use
*/
class creaBruker_ICUBE_EXPORT BrukerDataset
{
    typedef std::map<std::string, BrukerFieldData> BrukerMapType;
    
public:
    /**
     * Constructor
     */
	BrukerDataset();
    
    /**
     * Copy Constructor
     */
    BrukerDataset(BrukerDataset const & dataset);
    
    /**
     * Destructor
     */
	virtual ~BrukerDataset();
    
    /**
     * Read (and parse) a given file
     * @param FileToRead : file path
     * @return : true if read is succeful, false otherwise
     */
	bool LoadFile(std::string FileToRead);
    
    /**
     * Parse a given string
     * @param data : string to parse
     */
    void Parse(std::string const & data);
    
    /**
     * Parse a given stream buffer
     * @param streamdata : buffer to parse
     */
    void Parse(std::istream & streamdata);
    
    /**
     * Return this as string. (Only used to debug)
     * @return this as string
     */
    std::string toString() const;
    
    /**
     * Modify values for a given key
     * @param key : search key
     * @param value : new value
     */
    void SetFieldData(std::string const & key, 
                      BrukerFieldData const & value);
    
    /**
     * Return values for a given key
     * @param key : search key
     * @return values
     */
    BrukerFieldData GetFieldData(std::string key) const;
    
    /**
     * @return : true if dataset contains key, false otherwise
     */
    bool HasFieldData(std::string key) const;

protected:

private:
    /**
     * Contains all BrukerDataset elements
     */
    BrukerMapType BrukerHeaderMap;
};

#endif
