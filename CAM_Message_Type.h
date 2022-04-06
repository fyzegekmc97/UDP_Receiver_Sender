//
// Created by feyzi on 24.03.2022.
//

#ifndef UDP_RECEIVER_SENDER_CAM_MESSAGE_TYPE_H
#define UDP_RECEIVER_SENDER_CAM_MESSAGE_TYPE_H

#pragma once
#include <cstdint>
#include <string>
#include <vector>

struct Altitude {
    int64_t altitude_value;
    std::string altitude_confidence;
};

typedef Altitude Altitude ;

struct PositionConfidenceEllipse {
    int64_t semi_major_confidence;
    int64_t semi_minor_confidence;
    int64_t semi_major_orientation;
};

typedef PositionConfidenceEllipse PositionConfidenceEllipse ;

struct ReferencePosition {
    int64_t latitude;
    int64_t longitude;
    PositionConfidenceEllipse position_confidence_ellipse;
    Altitude altitude;
};

struct BasicContainer {
    int64_t station_type;
    ReferencePosition reference_position;
};

struct Curvature {
    int64_t curvature_value;
    std::string curvature_confidence;
};

struct Heading {
    int64_t heading_value;
    int64_t heading_confidence;
};

struct LongitudinalAcceleration {
    int64_t longitudinal_acceleration_value;
    int64_t longitudinal_acceleration_confidence;
};

struct Speed {
    int64_t speed_value;
    int64_t speed_confidence;
};

struct VehicleLength {
    int64_t vehicle_length_value;
    std::string vehicle_length_confidence_indication;
};

struct YawRate {
    int64_t yaw_rate_value;
    std::string yaw_rate_confidence;
};

struct BasicVehicleContainerHighFrequency {
    Heading heading;
    Speed speed;
    std::string drive_direction;
    VehicleLength vehicle_length;
    int64_t vehicle_width;
    LongitudinalAcceleration longitudinal_acceleration;
    Curvature curvature;
    std::string curvature_calculation_mode;
    YawRate yaw_rate;
    std::string acceleration_control;
};

struct HighFrequencyContainer {
    BasicVehicleContainerHighFrequency basic_vehicle_container_high_frequency;
};

struct PathPosition {
    int64_t delta_latitude;
    int64_t delta_longitude;
    int64_t delta_altitude;
};

struct PathHistory {
    PathPosition path_position;
    int64_t path_delta_time;
};

struct BasicVehicleContainerLowFrequency {
    std::string vehicle_role;
    std::string exterior_lights;
    std::vector<PathHistory> path_history;
};

struct LowFrequencyContainer {
    BasicVehicleContainerLowFrequency basic_vehicle_container_low_frequency;
};

struct CamParameters {
    BasicContainer basic_container;
    HighFrequencyContainer high_frequency_container;
    LowFrequencyContainer low_frequency_container;
};

struct Cam {
    int64_t generation_delta_time;
    CamParameters cam_parameters;
};

struct Header {
    int64_t protocol_version;
    int64_t message_id;
    int64_t station_id;
};

struct Welcome {
    Header header;
    Cam cam;
};


class CAM_Message_Type {

};


#endif //UDP_RECEIVER_SENDER_CAM_MESSAGE_TYPE_H
