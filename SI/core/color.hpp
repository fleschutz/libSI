#pragma once

#include <glm\glm.hpp>
#include <string>
#include <tower\TowStrucs.h>
#include <tower\core\fwd.hpp>

class QColor;

namespace core
{
	enum pen_style
	{
		ps_none = PS_NULL,
		ps_solid = PS_SOLID,
		ps_dashed = PS_DASH,
		ps_dotted = PS_DOT,
		ps_dashdot = PS_DASHDOT,
		ps_dashdotdot = PS_DASHDOTDOT,
	};

	enum brush_style
	{
		bs_horizontal = HS_HORIZONTAL,
		bs_vertical = HS_VERTICAL,
		bs_crossed = HS_CROSS,
		bs_bdia = HS_BDIAGONAL,
		bs_fdia = HS_FDIAGONAL,
		bs_diacrossed = HS_DIAGCROSS,
		bs_none = HS_API_MAX + 1,
		bs_solid,
		bs_fiftypercent,
	};

	// Cannot forward declare Qt enumerations (at least not standard conforming)
	// So declare functions only if Qt header is already included
#ifdef QNAMESPACE_H
	Qt::PenStyle qtPenStyle(pen_style penStyle);
	Qt::BrushStyle qtBrushStyle(brush_style brushStyle);
#endif

	class color
	{
	public:
		color();
		color(int r, int g, int b, int a = 255);
		color(double redF, double greenF, double blueF, double alphaF = 1.);
		/*explicit*/ color(glm::ivec3 colorVec);
		/*explicit*/ color(glm::ivec4 colorVec);
		/*explicit*/ color(QColor color);

		bool operator==(const color& other) const;
		bool operator!=(const color& other) const;

		int red() const;
		double redF() const;
		int green() const;
		double greenF() const;
		int blue() const;
		double blueF() const;
		int alpha() const;
		double alphaF() const;

		COLORREF rgb() const;
		glm::vec4 vec4() const;
		std::string string() const;

		static color toMonochrome(color toMono);
		static color fromString(const char* str);

		/*explicit*/ operator QColor() const;

	private:
		glm::ivec4 m_color;
	};

	template <>
	struct is_trivially_serializable<color> : std::true_type {};

	namespace detail
	{
		template <>
		struct value_tree_translator<pen_style>
		{
			static std::string to_string(const pen_style& style);
			static value_tree_value<pen_style> from_string(std::string_view text);
		};

		template <>
		struct value_tree_translator<brush_style>
		{
			static std::string to_string(const brush_style& style);
			static value_tree_value<brush_style> from_string(std::string_view text);
		};

		template <>
		struct value_tree_translator<color>
		{
			static std::string to_string(const color& color);
			static value_tree_value<color> from_string(std::string_view text);
		};

		template <>
		struct value_tree_translator<QColor>
		{
			static std::string to_string(const QColor& color);
			static value_tree_value<QColor> from_string(std::string_view text);
		};
	}
}