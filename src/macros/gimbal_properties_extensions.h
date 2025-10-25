
#define GBL_PROPERTIES__GEN_INST_EXTRACT_ARGNAME(argname, ...) argname
#define GBL_PROPERTIES__GEN_INST_EXTRACT_TYPE(argname, gen, permission, type...) type

#define GBL_PROPERTIES__GEN_SET_INST__(name__, param__) \
	case name__ ## _Property_Id_ ## param__: {\
		GblVariant_valueCopy(pValue, &pSelf-> param__);\
	}break;

#define GBL_PROPERTIES__GEN_SET_INST_(...) GBL_PROPERTIES__GEN_SET_INST__(__VA_ARGS__)

#define GBL_PROPERTIES__GEN_SET_INST(name__, param__) GBL_PROPERTIES__GEN_SET_INST_(name__, GBL_PROPERTIES__GEN_INST_EXTRACT_ARGNAME param__)

#define GBL_PROPERTIES__GEN_SET(name__, ...)\
	static GBL_RESULT name__ ## _GblObject_setProperty_(GblObject *pObject, const GblProperty *pProp, GblVariant *pValue){\
		name__ *pSelf = GBL_CAST(name__, pObject);\
		switch(pProp->id){\
			GBL_TUPLE_FOREACH(GBL_PROPERTIES__GEN_SET_INST, name__, (__VA_ARGS__))\
		}\
		return GBL_RESULT_SUCCESS;\
	}


//TODO: improve the variant function resolution algorithm. Unfortunately we cant use the type parameter in the argument tuple provided
//b/c GBL_X_TYPE immediately dissolves to a parenthesized expression... not what we were hoping for. As such we can't chain it to resolve new symbols
#define GBL_PROPERTIES__GEN_GET_INST__(name__, param__) \
	case name__ ## _Property_Id_ ## param__: {\
		 GblVariant_setFloat(pValue, pSelf->param__);\
	}break;

#define GBL_PROPERTIES__GEN_GET_INST_(...) GBL_PROPERTIES__GEN_GET_INST__(__VA_ARGS__)

#define GBL_PROPERTIES__GEN_GET_INST(name__, param__) GBL_PROPERTIES__GEN_GET_INST_(name__, GBL_PROPERTIES__GEN_INST_EXTRACT_ARGNAME param__)

#define GBL_PROPERTIES__GEN_GET(name__, ...)\
	static GBL_RESULT name__ ## _GblObject_property_(const GblObject *pObject, const GblProperty *pProp, GblVariant *pValue){\
		name__ *pSelf = GBL_CAST(name__, pObject);\
		switch(pProp->id){\
			GBL_TUPLE_FOREACH(GBL_PROPERTIES__GEN_GET_INST, name__, (__VA_ARGS__))\
		}\
		return GBL_RESULT_SUCCESS;\
	}

#define GBL_PROPERTIES_GETSET(name, ...) GBL_PROPERTIES(name, __VA_ARGS__) GBL_PROPERTIES__GEN_SET(name, __VA_ARGS__) GBL_PROPERTIES__GEN_GET(name, __VA_ARGS__)
#define GBL_PROPERTIES_SET(name, ...) GBL_PROPERTIES(name, __VA_ARGS__) GBL_PROPERTIES__GEN_SET(name, __VA_ARGS__) 
#define GBL_PROPERTIES_GET(name, ...) GBL_PROPERTIES(name, __VA_ARGS__) GBL_PROPERTIES__GEN_GET(name, __VA_ARGS__) 

#define GBL_PROPERTIES_HOOK_CLASS(name) \
			GblObjectClass* objKlass = GBL_OBJECT_CLASS(pClass);\
			objKlass->pFnSetProperty = name ##_GblObject_setProperty_;\
			objKlass->pFnProperty = name ## _GblObject_property_;
