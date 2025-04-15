#ifndef SAMPLEANGLEANDEMGCOSUMERPLUGIN_H
#define SAMPLEANGLEANDEMGCOSUMERPLUGIN_H

#include <EmgAndAngleAndComsumerPlugin.h>
#include <string>
#include <vector>
#include <map>

/**
 * @brief Minimal example implementation of the EmgAndAngleAndComsumerPlugin interface.
 *
 * This plugin receives muscle and DOF data from the CEINMS-RT core and returns
 * example EMG, angle, and torque outputs.
 */
class SampleAngleAndEmgAndConsumerPlugin : public EmgAndAngleAndComsumerPlugin {
public:
    /**
     * @brief Constructor.
     */
    SampleAngleAndEmgAndConsumerPlugin();

    /**
     * @brief Destructor.
     */
    ~SampleAngleAndEmgAndConsumerPlugin();

    /**
     * @brief Initialize the plugin with XML and execution configuration files.
     * @param xmlName Path to the XML configuration file.
     * @param executionName Path to the execution configuration.
     */
    void init(std::string& xmlName, std::string& executionName) override;

    /**
     * @brief Receive the list of DOF names from the core.
     * @param dofName Vector of DOF names.
     */
    void setDofName(const std::vector<std::string>& dofName) override;

    /**
     * @brief Receive DOF torque values from the core.
     * @param dofTorque Vector of DOF torque values.
     */
    void setDofTorque(const std::vector<double>& dofTorque) override;

    /**
     * @brief Receive DOF stiffness values (optional).
     * @param dofStiffness Vector of stiffness values.
     */
    void setDofStiffness(const std::vector<double>& dofStiffness) override;

    /**
     * @brief Set the simulation timestamp.
     * @param timeStamp Time in seconds.
     */
    void setOutputTimeStamp(const double& timeStamp) override;

    /**
     * @brief Receive the list of muscle names from the core.
     * @param muscleName Vector of muscle names.
     */
    void setMuscleName(const std::vector<std::string>& muscleName) override;

    /**
     * @brief Receive muscle force values from the core.
     * @param muscleForce Vector of muscle forces.
     */
    void setMuscleForce(const std::vector<double>& muscleForce) override;

    /**
     * @brief Receive muscle fiber lengths (optional).
     * @param muscleFiberLength Vector of fiber lengths.
     */
    void setMuscleFiberLength(const std::vector<double>& muscleFiberLength) override;

    /**
     * @brief Receive muscle fiber velocities (optional).
     * @param muscleFiberVelocity Vector of fiber velocities.
     */
    void setMuscleFiberVelocity(const std::vector<double>& muscleFiberVelocity) override;

    /**
     * @brief Get the current simulation time.
     * @return Reference to current timestamp.
     */
    const double& getTime() override;

    /**
     * @brief Get the list of DOF names.
     * @return Vector of DOF names.
     */
    const std::vector<std::string>& GetDofName() override;

    /**
     * @brief Get the EMG signal map (mocked values).
     * @return Map of muscle name to EMG value.
     */
    const std::map<std::string, double>& GetDataMapEMG() override;

    /**
     * @brief Get the angle data map (mocked values).
     * @return Map of DOF name to angle value.
     */
    const std::map<std::string, double>& GetDataMapAngle() override;

    /**
     * @brief Get the torque data map received from the core.
     * @return Map of DOF name to torque value.
     */
    const std::map<std::string, double>& GetDataMapTorque() override;

    /**
     * @brief Stop the plugin.
     */
    void stop() override;

    /**
     * @brief Set output and optional input directory paths.
     * @param outDirectory Output directory.
     * @param inDirectory Optional input directory.
     */
    void setDirectory(std::string outDirectory, std::string inDirectory = std::string()) override;

    /**
     * @brief Set verbosity level.
     * @param verbose Verbosity level.
     */
    void setVerbose(int verbose) override;

    /**
     * @brief Enable or disable recording.
     * @param record Boolean flag.
     */
    void setRecord(bool record) override;

private:
    std::vector<std::string> dofName_;                       ///< Names of degrees of freedom
    std::vector<std::string> muscleName_;                    ///< Names of muscles
    std::map<std::string, double> dofTorque_;                ///< DOF torque data
    std::map<std::string, double> dataAngle_;                ///< Mock angle data
    std::map<std::string, double> dataEmg_;                  ///< Mock EMG data
    std::map<std::string, double> muscleForce_;              ///< Muscle force data
    std::map<std::string, double> dofStiffness_;      ///< DOF stiffness data
    std::map<std::string, double> fiberLength_;       ///< Muscle fiber length data
    std::map<std::string, double> fiberVelocity_;     ///< Muscle fiber velocity data
    int verbosity_;                                    ///< Verbosity level (optional)


    double timeStamp_;                                       ///< Current time stamp
    bool record_;                                            ///< Recording flag
    std::string outDirectory_;                               ///< Output directory path
};

#endif
