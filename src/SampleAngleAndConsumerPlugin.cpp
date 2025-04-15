#include "SampleAngleAndConsumerPlugin.h"
#include <iostream>

SampleAngleAndConsumerPlugin::SampleAngleAndConsumerPlugin()
    : timeStamp_(0.0), record_(false), outDirectory_("output") {}

SampleAngleAndConsumerPlugin::~SampleAngleAndConsumerPlugin() {}

void SampleAngleAndConsumerPlugin::init(std::string& executableXMLFileName) {
    std::cout << "[Plugin] Initialized with XML file: " << executableXMLFileName << std::endl;
    // The core calls this function once to initialize the plugin using the execution XML.
    // Use ExecutionXmlReader if you need to extract values from the file.
}

void SampleAngleAndConsumerPlugin::setMuscleForce(const std::vector<double>& muscleForce) {
    // Core provides muscle force data here every time step.
    // You can store or process this data as needed.
}

void SampleAngleAndConsumerPlugin::setMuscleFiberLength(const std::vector<double>& muscleFiberLength) {
    // Core provides muscle fiber lengths each step.
}

void SampleAngleAndConsumerPlugin::setMuscleFiberVelocity(const std::vector<double>& muscleFiberVelocity) {
    // Core provides fiber velocity data.
}

void SampleAngleAndConsumerPlugin::setDofName(const std::vector<std::string>& dofName) {
    dofName_ = dofName;
    std::cout << "[Plugin] DOF names received from core: ";
    for (const auto& name : dofName_) std::cout << name << " ";
    std::cout << std::endl;
}

void SampleAngleAndConsumerPlugin::setDofTorque(const std::vector<double>& dofTorque) {
    // Core provides torque data for each DOF every time step.
    for (size_t i = 0; i < dofName_.size() && i < dofTorque.size(); ++i) {
        dataTorque_[dofName_[i]] = dofTorque[i];
    }
}

void SampleAngleAndConsumerPlugin::setDofStiffness(const std::vector<double>& dofStiffness) {
    // Core may provide joint stiffness if enabled.
}

void SampleAngleAndConsumerPlugin::setMuscleName(const std::vector<std::string>& muscleName) {
    // Core sends muscle names at the beginning.
}

void SampleAngleAndConsumerPlugin::setOutputTimeStamp(const double& timeStamp) {
    // Core sends the current simulation time step.
    timeStamp_ = timeStamp;
}

void SampleAngleAndConsumerPlugin::setMuscleForcePassive(const std::vector<double>& muscleForcePassive) {
    // Passive muscle force per time step.
}

void SampleAngleAndConsumerPlugin::setMuscleForceActive(const std::vector<double>& muscleForceActive) {
    // Active muscle force per time step.
}

void SampleAngleAndConsumerPlugin::setMuscleTendonStrain(const std::vector<double>& tendonStrain) {
    // Muscle-tendon unit strain.
}

void SampleAngleAndConsumerPlugin::setTendonStrain(const std::vector<double>& tendonStrain) {
    // Direct tendon strain.
}

const double& SampleAngleAndConsumerPlugin::GetAngleTimeStamp() {
    // Core will call this to get the timestamp of the angle data.
    return timeStamp_;
}

const std::vector<std::string>& SampleAngleAndConsumerPlugin::GetDofName() {
    // Core may call this to confirm DOF names.
    return dofName_;
}

const std::map<std::string, double>& SampleAngleAndConsumerPlugin::GetDataMap() {
    // Core expects this to return a map of DOF names to angle values.
    // Here, we provide mock angle values (e.g., 0.1) for each DOF.
    dataAngle_.clear();
    for (const auto& name : dofName_) {
        dataAngle_[name] = 0.1;
    }
    return dataAngle_;
}

const std::map<std::string, double>& SampleAngleAndConsumerPlugin::GetDataMapTorque() {
    // Core may call this to read back the torque data previously provided.
    return dataTorque_;
}

void SampleAngleAndConsumerPlugin::stop() {
    // Called by the core at the end of the run.
    std::cout << "[Plugin] Stop called. Cleaning up." << std::endl;
}

void SampleAngleAndConsumerPlugin::setDirectory(std::string outDirectory, std::string inDirectory) {
    // Called by the core to set the plugin’s output (and optionally input) directory.
    outDirectory_ = outDirectory;
}

void SampleAngleAndConsumerPlugin::setVerbose(int verbose) {
    // Optional verbosity control.
}

void SampleAngleAndConsumerPlugin::setRecord(bool record) {
    // Called to control data logging inside the plugin.
    record_ = record;
}

// Factory functions for dynamic plugin loading
#ifdef UNIX
extern "C" AngleAndConsumerPlugin* create() {
    return new SampleAngleAndConsumerPlugin;
}

extern "C" void destroy(AngleAndConsumerPlugin* p) {
    delete p;
}
#endif

#ifdef WIN32
extern "C" __declspec(dllexport) AngleAndConsumerPlugin* __cdecl create() {
    return new SampleAngleAndConsumerPlugin;
}

extern "C" __declspec(dllexport) void __cdecl destroy(AngleAndConsumerPlugin* p) {
    delete p;
}
#endif
