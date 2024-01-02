#include "Connection.h"

///<summary>
///All connections are bidirectional
///</summary>
Connection::Connection(int _cost, std::string _fromNodeId, std::string _toNodeId)
{
	cost = _cost;
	fromNodeId = _fromNodeId;
	toNodeId = _toNodeId;
}

Connection::~Connection()
{
}
