#include "Component.h"

namespace EF {
	const int Component::InvalidID = -1;

	Component::Component(int id) {
		init(id);
	}

	Component::~Component() {
		destroy();
	}

	Component::Component(const Component& cp) {
		copy(cp);
	}

	Component&
	Component::operator=(const Component& cp) {
		if(this != &cp){
			destroy();
			copy(cp);
		}

		return *this;
	}

	int 
	Component::getID() const {
		return _id;
	}

	void 
	Component::setID(int id) {
		_id = id;
	}

	Json::Value
	Component::serialize() const {
		Json::Value val;
		val["id"] = _id;

		return val;
	}

	void
	Component::deserialize(Json::Value& root) {
		_id = root.get("id", InvalidID).asInt();
	}

	void
	Component::copy(const Component& cp){
		_id = cp._id;
	}

	void
	Component::init(int id){
		_id = id;
	}

	void
	Component::destroy(){
		_id = InvalidID;
	}
}