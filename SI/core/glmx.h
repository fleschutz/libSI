#pragma once

/// Conversion methods between glm types and other vector/matrix/quaternion implementations

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/compatibility.hpp>
#include <glm/gtc/constants.hpp>

#include <tower\core\vec.hpp>

#ifdef GLMX_ENABLE_BULLET_CONVERSIONS

#include <btBulletCollisionCommon.h>

namespace glmx 
{
	inline ::btVector3 btVector3(const glm::vec3& v)
	{
		return ::btVector3(v.x, v.y, v.z);
	}

	inline ::btVector3 btVector3(const Vec3& v)
	{
		return ::btVector3(static_cast<btScalar>(v.x), static_cast<btScalar>(v.y), static_cast<btScalar>(v.z));
	}

	inline ::btQuaternion btQuaternion(const glm::vec3& euler)
	{
		return ::btQuaternion(glm::radians(euler.y), glm::radians(euler.x), glm::radians(euler.z));
	}

	inline ::btTransform btTransform(const glm::vec3& position, const glm::vec3& rotation)
	{
		return ::btTransform(glmx::btQuaternion(rotation), glmx::btVector3(position));
	}

	inline glm::vec3 vec3(const ::btVector3& v)
	{
		return glm::vec3(v.getX(), v.getY(), v.getZ());
	}

	inline glm::highp_dvec3 dvec3(const ::btVector3& v)
	{
		return glm::highp_dvec3(static_cast<double>(v.getX()), static_cast<double>(v.getY()), static_cast<double>(v.getZ()));
	}

	inline ::Vec3 Vec3(const ::btVector3& v)
	{
		return { v.getX(), v.getY(), v.getZ() };
	}

	inline glm::quat quat(const ::btQuaternion& q)
	{
		auto temp = glm::dquat(q.getW(), q.getX(), q.getY(), q.getZ());
		auto retVal = static_cast<glm::quat>(temp);

		return retVal;
	}

	inline glm::vec3 eulerAngles(const btScalar qx, const btScalar qy, const btScalar qz, const btScalar qw)
	{
		btScalar yaw = std::atan2(2.0f * qy * qw - 2.0f * qx * qz, 1.0f - 2.0f * qy * qy - 2.0f * qz * qz);
		btScalar pitch = glm::asin(2.0f * qx * qy + 2.0f * qz * qw);
		btScalar roll = std::atan2(2.0f * qx * qw - 2.0f * qy * qz, 1.0f - 2.0f * qx * qx - 2.0f * qz * qz);
	
		if((qx * qy + qz * qw) == 0.5f)
		{
			// north pole
			yaw = 2.0f * std::atan2(qx, qw);
			roll = 0.0f;
		}
		else if((qx * qy + qz * qw) == -0.5f)
		{
			// south pole
			yaw = -2.0f * std::atan2(qx, qw);
			roll = 0.0f;
		}
	
		if(yaw < 0.0f)
			yaw = glm::pi<btScalar>() + yaw;
		
		return glm::vec3(-roll, yaw, pitch);
	}

	inline glm::vec3 eulerAngles(const ::btQuaternion& q) 
	{
		return eulerAngles(q.getX(), q.getY(), q.getZ(), q.getW());
	}

	inline glm::vec3 eulerAngles(const glm::quat& q) 
	{
		return eulerAngles(q.x, q.y, q.z, q.w);
	}

	inline glm::vec3 eulerAngles(const ::btMatrix3x3& m)
	{
		::btQuaternion q;
		m.getRotation(q);

		return eulerAngles(q);
	}
}

#endif
