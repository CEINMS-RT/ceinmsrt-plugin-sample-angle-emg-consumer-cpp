#include "SampleAngleAndEmgAndConsumerPlugin.h"
#include <iostream>

SampleAngleAndEmgAndConsumerPlugin::SampleAngleAndEmgAndConsumerPlugin()
    : timeStamp_(0.0), record_(false), outDirectory_("output") {}

SampleAngleAndEmgAndConsumerPlugin::~SampleAngleAndEmgAndConsumerPlugin() {}

void SampleAngleAndEmgAndConsumerPlugin::init(std::string& xmlName, std::string& executionName) {
    // Save the provided configuration names (if needed for parsing or logging)
    std::cout << "[Plugin] Initialized with XML: " << xmlName
              << ", Execution: " << executionName << std::endl;

    // You can parse the XML or execution file here if needed.
}

void SampleAngleAndEmgAndConsumerPlugin::setDofName(const std::vector<std::string>& dofName) {
    dofName_ = dofName;
    std::cout << "[Plugin] DOF names received and stored." << std::endl;

    // You can use these names for indexing, logging, or mapping.
}

void SampleAngleAndEmgAndConsumerPlugin::setDofTorque(const std::vector<double>& dofTorque) {
    // Store DOF torque values using DOF names
    for (size_t i = 0; i < dofName_.size() && i < dofTorque.size(); ++i) {
        dofTorque_[dofName_[i]] = dofTorque[i];
    }

    // You can use these torques for control, export, or feedback.
}

void SampleAngleAndEmgAndConsumerPlugin::setDofStiffness(const std::vector<double>& dofStiffness) {
    // Example: store to a map (mock values as index)
    for (size_t i = 0; i < dofName_.size() && i < dofStiffness.size(); ++i) {
        dofStiffness_[dofName_[i]] = dofStiffness[i];
    }

    // You can use this stiffness info in further biomechanical calculations.
}

void SampleAngleAndEmgAndConsumerPlugin::setOutputTimeStamp(const double& timeStamp) {
    timeStamp_ = timeStamp;

    // This timestamp can be used to align data, trigger events, or log entries.
}

void SampleAngleAndEmgAndConsumerPlugin::setMuscleName(const std::vector<std::string>& muscleName) {
    muscleName_ = muscleName;
    std::cout << "[Plugin] Muscle names received and stored." << std::endl;

    // These names can be used for EMG mapping or ordering.
}

void SampleAngleAndEmgAndConsumerPlugin::setMuscleForce(const std::vector<double>& muscleForce) {
    // Store muscle force values using muscle names
    for (size_t i = 0; i < muscleName_.size() && i < muscleForce.size(); ++i) {
        muscleForce_[muscleName_[i]] = muscleForce[i];
    }

    // You can use these values for analysis or plotting.
}

void SampleAngleAndEmgAndConsumerPlugin::setMuscleFiberLength(const std::vector<double>& muscleFiberLength) {
    // Store muscle fiber lengths (indexed by muscle name if needed)
    for (size_t i = 0; i < muscleName_.size() && i < muscleFiberLength.size(); ++i) {
        fiberLength_[muscleName_[i]] = muscleFiberLength[i];
    }

    // Useful for estimating tendon strain or muscle state.
}

void SampleAngleAndEmgAndConsumerPlugin::setMuscleFiberVelocity(const std::vector<double>& muscleFiberVelocity) {
    // Store muscle fiber velocities
    for (size_t i = 0; i < muscleName_.size() && i < muscleFiberVelocity.size(); ++i) {
        fiberVelocity_[muscleName_[i]] = muscleFiberVelocity[i];
    }

    // You can use these for dynamic behavior modeling.
}

const double& SampleAngleAndEmgAndConsumerPlugin::getTime() {
    // Returns the latest time stamp received from the core
    return timeStamp_;
}

const std::vector<std::string>& SampleAngleAndEmgAndConsumerPlugin::GetDofName() {
    return dofName_;
}

const std::map<std::string, double>& SampleAngleAndEmgAndConsumerPlugin::GetDataMapEMG() {
    dataEmg_.clear();

    // Generate or retrieve EMG values (mocked here)
    for (const auto& name : muscleName_) {
        dataEmg_[name] = 0.5; // Example constant value
    }

    // You can replace this with real EMG processing logic
    return dataEmg_;
}

const std::map<std::string, double>& SampleAngleAndEmgAndConsumerPlugin::GetDataMapAngle() {
    dataAngle_.clear();

    // Generate or retrieve angle values (mocked here)
    for (const auto& name : dofName_) {
        dataAngle_[name] = 0.1; // Example constant angle
    }

    // You can replace this with real angle data or simulation
    return dataAngle_;
}

const std::map<std::string, double>& SampleAngleAndEmgAndConsumerPlugin::GetDataMapTorque() {
    // Return the most recently received DOF torques
    return dofTorque_;
}

void SampleAngleAndEmgAndConsumerPlugin::stop() {
    std::cout << "[Plugin] Stop called. Cleaning up." << std::endl;

    // Perform cleanup or final logging here if needed.
}

void SampleAngleAndEmgAndConsumerPlugin::setDirectory(std::string outDirectory, std::string inDirectory) {
    outDirectory_ = outDirectory;

    // Use this directory path to store plugin output files or logs.
}

void SampleAngleAndEmgAndConsumerPlugin::setVerbose(int verbose) {
    // Example: store the verbosity level if needed (not used here)
    verbosity_ = verbose;
}

void SampleAngleAndEmgAndConsumerPlugin::setRecord(bool record) {
    record_ = record;

    // You can use this flag to conditionally enable logging or output writing.
}
