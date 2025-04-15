ADD_LIBRARY( SampleAngleAndConsumerPlugin SHARED SampleAngleAndConsumerPlugin.cpp)


TARGET_LINK_LIBRARIES( SampleAngleAndConsumerPlugin
	FileIO
	XMLIKIDInterpreter
	XMLExecutionInterpreter
	${Boost_LIBRARIES}
	XercesC::XercesC
	FileLogger
)