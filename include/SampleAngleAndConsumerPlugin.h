#ifndef SAMPLEANGLEANDCONSUMERPLUGIN_H
#define SAMPLEANGLEANDCONSUMERPLUGIN_H

#include <AngleAndConsumerPlugin.h>
#include <string>
#include <vector>
#include <map>

/**
 * @brief Sample implementation of the AngleAndConsumerPlugin interface.
 *
 * This minimal example shows how to implement a plugin that interacts with the CEINMS-RT core.
 * The core system will call `set*()` methods at the end of a timestep to provide updated data calculated by the core, and expects the plugin to
 * return processed or stored values when calling `get*()` methods.
 */
#ifdef WIN32
class __declspec(dllexport) SampleAngleAndConsumerPlugin : public AngleAndConsumerPlugin {
#endif
#ifdef UNIX
class SampleAngleAndConsumerPlugin : public AngleAndConsumerPlugin {
#endif
public:
    /**
     * @brief Constructor.
     */
    SampleAngleAndConsumerPlugin();

    /**
     * @brief Destructor.
     */
    ~SampleAngleAndConsumerPlugin();

    /**
     * @brief Initialize plugin using XML configuration file.
     * Called by CEINMS-RT to configure the plugin.
     * @param executableXMLFileName Path to XML configuration.
     */
    void init(std::string& executableXMLFileName);

    /**
     * @brief Set muscle force values.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param muscleForce Vector of muscle forces.
     */
    void setMuscleForce(const std::vector<double>& muscleForce);

    /**
     * @brief Set muscle fiber lengths.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param muscleFiberLength Vector of fiber lengths.
     */
    void setMuscleFiberLength(const std::vector<double>& muscleFiberLength);

    /**
     * @brief Set muscle fiber velocities.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param muscleFiberVelocity Vector of fiber velocities.
     */
    void setMuscleFiberVelocity(const std::vector<double>& muscleFiberVelocity);

    /**
     * @brief Set degree of freedom (DOF) names.
     * Called once by CEINMS-RT for mapping purposes.
     * @param dofName Vector of DOF names.
     */
    void setDofName(const std::vector<std::string>& dofName);

    /**
     * @brief Set torque values for each DOF.
     * Called every time step by CEINMS-RT.
     * @param dofTorque Vector of torque values.
     */
    void setDofTorque(const std::vector<double>& dofTorque);

    /**
     * @brief Set stiffness values for each DOF.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param dofStiffness Vector of stiffness values.
     */
    void setDofStiffness(const std::vector<double>& dofStiffness);

    /**
     * @brief Set muscle names.
     * Called once by CEINMS-RT for mapping purposes.
     * @param muscleName Vector of muscle names.
     */
    void setMuscleName(const std::vector<std::string>& muscleName);

    /**
     * @brief Set output time stamp.
     * Called by CEINMS-RT every time step.
     * @param timeStamp Time stamp value.
     */
    void setOutputTimeStamp(const double& timeStamp);

    /**
     * @brief Set passive muscle forces.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param muscleForcePassive Vector of passive muscle forces.
     */
    void setMuscleForcePassive(const std::vector<double>& muscleForcePassive);

    /**
     * @brief Set active muscle forces.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param muscleForceActive Vector of active muscle forces.
     */
    void setMuscleForceActive(const std::vector<double>& muscleForceActive);

    /**
     * @brief Set muscle-tendon strain values.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param tendonStrain Vector of strain values.
     */
    void setMuscleTendonStrain(const std::vector<double>& tendonStrain);

    /**
     * @brief Set tendon strain values.
     * Called by CEINMS-RT at the end of a timestep to provide updated data calculated by the core.
     * @param tendonStrain Vector of strain values.
     */
    void setTendonStrain(const std::vector<double>& tendonStrain);

    /**
     * @brief Get time stamp associated with angle data.
     * Called by CEINMS-RT to read time-aligned output from the plugin.
     * @return Reference to time stamp.
     */
    const double& GetAngleTimeStamp();

    /**
     * @brief Get DOF names previously set.
     * Called by CEINMS-RT to verify or retrieve DOF naming.
     * @return Vector of DOF names.
     */
    const std::vector<std::string>& GetDofName();

    /**
     * @brief Get angle data.
     * Called by CEINMS-RT to read angle values computed or recorded by the plugin.
     * @return Map of DOF name to angle value.
     */
    const std::map<std::string, double>& GetDataMap();

    /**
     * @brief Get torque data.
     * Called by CEINMS-RT to retrieve torque data stored by the plugin.
     * @return Map of DOF name to torque value.
     */
    const std::map<std::string, double>& GetDataMapTorque();

    /**
     * @brief Stop plugin execution.
     * Called by CEINMS-RT during shutdown or reset.
     */
    void stop();

    /**
     * @brief Set file I/O directories.
     * @param outDirectory Path to output directory.
     * @param inDirectory Optional path to input directory.
     */
    void setDirectory(std::string outDirectory, std::string inDirectory = std::string());

    /**
     * @brief Set verbosity level.
     * Optional call by CEINMS-RT or user for debugging.
     * @param verbose Verbosity level (unused in this sample).
     */
    void setVerbose(int verbose);

    /**
     * @brief Enable or disable recording.
     * Optional call by CEINMS-RT. 
     * @param record Boolean flag to enable recording.
     */
    void setRecord(bool record);

private:
    std::vector<std::string> dofName_;                   ///< DOF names
    double timeStamp_;                                   ///< Timestamp for angle data
    std::string outDirectory_;                           ///< Output directory path
    bool record_;                                        ///< Whether recording is enabled
};

#endif