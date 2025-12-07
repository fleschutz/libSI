#pragma once

#include <string>
#include <string_view>
#include <memory>
#include <tower/core/range.hpp>

namespace core
{
	/**
		SoundElement can be used to control the playback of a given sound file.
		Doesn't own backed sound resources, e.g. no need to keep object if object is not needed.
	*/
	class SoundElement
	{
		friend class SoundDevice;
	public:
		// Internal only
		class Impl;

		/// Sound mode types
		enum PlayMode
		{
			SingleShot, ///< Sound will be played once
			Continuous, ///< Sound will be played in loop
		};

		// Internal only
		explicit SoundElement(Impl* impl);
		~SoundElement();

		// Internal only
		SoundElement(const SoundElement &) = delete;
		SoundElement & operator=(const SoundElement &) = delete;

		/// This function will start play sound element
		void play(PlayMode playMode = PlayMode::SingleShot);

		/// Stop to play sound element
		void stop();

		/// Check playing status of sound element
		bool isPlaying() const;

		/// Check playing status and play mode of sound element
		bool isContinuousPlaying() const;

		/// This function will return path to the WAV file
		std::string path() const;

		/**
		  This function will detach sound element of the main thread,
		  DO NOT USE any other SoundElement functions after detach();
		*/
		void detach();

	private:
		// Internal only
		Impl* m_rawPToImpl;
	};

	/**
		SoundDeviceControl can be used to play sounds to a specific device.
		Note: This is only a control object.
	*/
	class SoundDevice
	{
	public:
		// Internal only
		class Impl;

		// internal use
		SoundDevice(void* lpGUID, std::string_view deviceName, std::string_view deviceLocation, std::string_view deviceDescription, bool isDefaultDevice);

		// Internal only
		~SoundDevice();
		SoundDevice(const SoundDevice &) = delete;

		// Internal only
		SoundDevice & operator=(SoundDevice &) = delete;

		/* Device name consist of the following parameters:
			- vendor code that the USB committee assigns to the vendor
			- product code that the vendor assigns to the device
			- specific information according to the device type (USB, HDAUDIO and etc)
			- example USB\VID_045E&PID_070F&REV_0100&MI_00
		*/
		std::string deviceName() const;

		/* Device description assigned by Windows
			- example Headset Earphone Microsoft LifeChat LX-3000
		*/
		std::string deviceDescription() const;

		/* In case of identical devices device name will be the same
		   and in this case should be used device location. Each driver has
		   parameter "Location".
			- example 0000.0014.0000.009.000.000.000.000.000
		*/
		std::string deviceLocation() const;

		/// Check if device is default in Windows
		bool isDefaultDevice() const;

		/*
		  Create sound element function will add sound element to
		  the local container of the current device

		  \param path - path to the WAV file
		*/
		std::unique_ptr<core::SoundElement> createSoundElement(std::string_view path);

		/// This function will return list of available devices in Windows
		static core::range<SoundDevice*> availableDevices();

		/// This function will return default device in Windows
		static SoundDevice* defaultDevice();

		/// This function will return available device in Windows by given hardware id name and location or null pointer if device was not found
		static SoundDevice* deviceByNameLocation(std::string_view deviceName, std::string_view deviceLocation = "");

		/* This function will return information that should be logged. This information consists of:
			- Device description
			- Device name
			- Device location
		*/
		static std::string logInfo();

	private:
		// Internal only
		std::unique_ptr<Impl> m_impl;
	};

	/*
	  Play sound on default device. This is shorthand for defaultSoundDevice()->play(...). When the function will be used
	  sound will be played and will be deleted.

	  \param path - path to the WAV file
	*/
	void playSound(const std::string& path);
}