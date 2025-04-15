ADD_LIBRARY( SampleAngleAndEmgAndConsumerPlugin SHARED SampleAngleAndEmgAndConsumerPlugin.cpp)


TARGET_LINK_LIBRARIES( SampleAngleAndEmgAndConsumerPlugin
	FileIO
	XMLIKIDInterpreter
	XMLExecutionInterpreter
	${Boost_LIBRARIES}
	XercesC::XercesC
	FileLogger
)