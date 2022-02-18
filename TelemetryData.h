
#include "Vehicle.h"
#ifndef uint
typedef unsigned int uint;
#endif // !uint

#ifndef sbyte
typedef char sbyte;
#endif // !sbyte

#ifndef byte
typedef unsigned char byte;
#endif // !byte

#ifndef UInt16
typedef unsigned short int UInt16;
#endif // !UInt16

typedef struct{
	int IsRaceOn;
	uint TimestampMS ;
	float EngineMaxRPM ;
	float EngineIdleRPM ;
	float EngineCurrentRPM ;
	/// <summary>
	/// Right (x) position axis in local space
	/// </summary>
	float AccelerationX ;
	/// <summary>
	/// Up (y) position axis in local space
	/// </summary>
	float AccelerationY ;
	/// <summary>
	/// Forward (z) position axis in local space
	/// </summary>
	float AccelerationZ ;
	/// <summary>
	/// Right (x) velocity axis in local space
	/// </summary>
	float VelocityX ;
	/// <summary>
	/// Up (y) velocity axis in local space
	/// </summary>
	float VelocityY ;
	/// <summary>
	/// Forward (z) velocity axis in local space
	/// </summary>
	float VelocityZ ;
	/// <summary>
	/// Pitch (x) velocity in local space
	/// </summary>
	float AngularVelocityX ;
	/// <summary>
	/// Yaw (y) velocity in local space
	/// </summary>
	float AngularVelocityY ;
	/// <summary>
	/// Roll (z) velocity in local space
	/// </summary>
	float AngularVelocityZ ;
	float Yaw ;
	float Pitch ;
	float Roll ;
	/// <summary>
	/// Normalized suspension travel (Front Left Tire) - 0.0 = max stretch | 1.0 = max compression
	/// </summary>
	float NormalizedSuspensionTravelFrontLeft ;
	/// <summary>
	/// Normalized suspension travel (Front Right Tire) - 0.0 = max stretch | 1.0 = max compression
	/// </summary>
	float NormalizedSuspensionTravelFrontRight ;
	/// <summary>
	/// Normalized suspension travel (Rear Left Tire) - 0.0 = max stretch | 1.0 = max compression
	/// </summary>
	float NormalizedSuspensionTravelRearLeft ;
	/// <summary>
	/// Normalized suspension travel (Rear Right Tire) - 0.0 = max stretch | 1.0 = max compression
	/// </summary>
	float NormalizedSuspensionTravelRearRight ;
	/// <summary>
	/// Normalized tire slip ratio (Front Left Tire) - 0.0 = 100% grip and |ratio| > 1.0 means loss of grip
	/// </summary>
	float TireSlipRatioFrontLeft ;
	/// <summary>
	/// Normalized tire slip ratio (Front Right Tire) - 0.0 = 100% grip and |ratio| > 1.0 means loss of grip
	/// </summary>
	float TireSlipRatioFrontRight ;
	/// <summary>
	/// Normalized tire slip ratio (Rear Left Tire) - 0.0 = 100% grip and |ratio| > 1.0 means loss of grip
	/// </summary>
	float TireSlipRatioRearLeft ;
	/// <summary>
	/// Normalized tire slip ratio (Rear Right Tire) - 0.0 = 100% grip and |ratio| > 1.0 means loss of grip
	/// </summary>
	float TireSlipRatioRearRight ;
	/// <summary>
	/// Wheel rotation speed in radians/sec - Front Left Tire
	/// </summary>
	float WheelRotationSpeedFrontLeft ;

	/// <summary>
	/// Wheel rotation speed in radians/sec - Front Right Tire
	/// </summary>
	float WheelRotationSpeedFrontRight ;

	/// <summary>
	/// Wheel rotation speed in radians/sec - Rear Left Tire
	/// </summary>
	float WheelRotationSpeedRearLeft ;

	/// <summary>
	/// Wheel rotation speed in radians/sec - Rear Right Tire
	/// </summary>
	float WheelRotationSpeedRearRight ;



	/// <summary>
	/// Returns 1 when the front left wheel is on a rumble strip, 0 when not
	/// </summary>
	int WheelOnRumbleStripFrontLeft ;

	/// <summary>
	/// Returns 1 when the front right wheel is on a rumble strip, 0 when not
	/// </summary>
	int WheelOnRumbleStripFrontRight ;

	/// <summary>
	/// Returns 1 when the rear left wheel is on a rumble strip, 0 when not
	/// </summary>
	int WheelOnRumbleStripRearLeft ;

	/// <summary>
	/// Returns 1 when the rear right wheel is on a rumble strip, 0 when not
	/// </summary>
	int WheelOnRumbleStripRearRight ;



	// From 0 to 1, where 1 is the deepest puddle
	float WheelInPuddleDepthFrontLeft ;
	float WheelInPuddleDepthFrontRight ;
	float WheelInPuddleDepthRearLeft ;
	float WheelInPuddleDepthRearRight ;

	// Non-dimensional surface rumble values passed to controller force feedback
	float SurfaceRumbleFrontLeft ;
	float SurfaceRumbleFrontRight ;
	float SurfaceRumbleRearLeft ;
	float SurfaceRumbleRearRight ;

	// Tire normalized slip angle, = 0 means 100% grip and |angle| > 1.0 means loss of grip.
	float TireSlipAngleFrontLeft ;
	float TireSlipAngleFrontRight ;
	float TireSlipAngleRearLeft ;
	float TireSlipAngleRearRight ;

	// Tire normalized combined slip, = 0 means 100% grip and |slip| > 1.0 means loss of grip.
	float TireCombinedSlipFrontLeft ;
	float TireCombinedSlipFrontRight ;
	float TireCombinedSlipRearLeft ;
	float TireCombinedSlipRearRight ;

	// Actual suspension travel in meters
	float SuspensionTravelFrontLeft ;
	float SuspensionTravelFrontRight ;
	float SuspensionTravelRearLeft ;
	float SuspensionTravelRearRight;

	int CarOrdinal;
	enum CarClass carClass;
	int CarPI;
	enum DrivetrainType drivetrainType;
	int NumCylinders ;

	float PositionX ;
	float PositionY ;
	float PositionZ ;

	float Speed ;
	float Power ;
	float Torque ;

	float TireTempFrontLeft ;
	float TireTempFrontRight ;
	float TireTempRearLeft ;
	float TireTempRearRight ;

	float Boost ;
	float Fuel ;
	float DistanceTraveled ;


	float BestLap ;
	float LastLap ;
	float CurrentLap ;
	float CurrentRaceTime ;
	UInt16 LapNumber ;
	byte RacePosition ;

	byte Accel ;
	byte Brake ;
	byte Clutch ;

	byte Handbrake ;
	byte Gear ;
	sbyte Steer ;

	sbyte NormalizedDrivingLine ;
	sbyte NormalizedAIBrakeDifference ;
}Horizon4TelmetryData;

Horizon4TelmetryData* data;

int GetMPH(){
	return (int)(data->VelocityZ * 2.23694f);
}

int GetKMPH() {
	return (int)(data->VelocityZ * 3.6f);
}

void bindData(char* buffer) {
	data = (Horizon4TelmetryData*)buffer;
}