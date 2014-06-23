
#include "RulesDocument.h"

RulesDocument::RulesDocument()
{
}

RulesDocument::~RulesDocument()
{
    std::vector<RulesAction*>::iterator it = _ActionsList.begin();
    for (; it != _ActionsList.end() ; ++it)
    {
        delete (*it);
    }
}

void RulesDocument::AddAction(RulesAction* action)
{
    if (action != NULL)
    {
        this->_ActionsList.push_back(action);
    }
}

void RulesDocument::AddAction(EActionType type, 
                              std::string const & elementName,
                              BrukerFieldData const & data, 
                              EValueRepresentation vr,
                              bool clean)
{
    RulesAction * action = new RulesAction(type);

    action->SetElement(elementName);
    action->SetValue(data.GetValueToString(clean));
    action->SetVR(vr);
        
    AddAction(action);
}

void RulesDocument::WriteDocument(std::string const & file)
{
    // Create document tree
    boost::property_tree::ptree proptree;
    
    // Create main Node : Rules
    boost::property_tree::ptree rootNode;
    
    // Create Actions Node
    boost::property_tree::ptree actionNode;
    
    // Foreach action
    std::vector<RulesAction*>::iterator it = _ActionsList.begin();
    for (; it != _ActionsList.end() ; ++it)
    {
        actionNode.add_child((*it)->GetTypeToString(), (*it)->toXMLNode());
    }
    
    // add node to root
    rootNode.add_child("Actions", actionNode);
    
    // add node to document tree
    proptree.add_child("Rules", rootNode);
    
    // Write file
    boost::property_tree::xml_writer_settings<char> settings('\t', 1);
    boost::property_tree::write_xml(file, proptree, std::locale(), settings);
}
