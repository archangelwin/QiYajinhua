#pragma once
#ifndef HTTPREQUEST_PARSER_HPP
#define HTTPREQUEST_PARSER_HPP
#include <tuple>
struct request;

class request_parser
{
public:
	request_parser();
	void reset();
	enum result_type{good,bad,indeterminate};

	template <typename InputIterator>
	std::tuple<result_type, InputIterator> parse(request& req,
		InputIterator begin, InputIterator end)
	{
		while (begin != end)
		{
			result_type result = consume(req, *begin++);
			if (result == good || result == bad)
				return std::make_tuple(result, begin);
		}
		return std::make_tuple(indeterminate, begin);
	}
private:
	result_type consume(request& req, char input);

	/// Check if a byte is an HTTP character.
	static bool is_char(int c);

	/// Check if a byte is an HTTP control character.
	static bool is_ctl(int c);

	/// Check if a byte is defined as an HTTP tspecial character.
	static bool is_tspecial(int c);

	/// Check if a byte is a digit.
	static bool is_digit(int c);

	/// The current state of the parser.
	enum state
	{
		method_start,
		method,
		uri,
		http_version_h,
		http_version_t_1,
		http_version_t_2,
		http_version_p,
		http_version_slash,
		http_version_major_start,
		http_version_major,
		http_version_minor_start,
		http_version_minor,
		expecting_newline_1,
		header_line_start,
		header_lws,
		header_name,
		space_before_header_value,
		header_value,
		expecting_newline_2,
		expecting_newline_3
	} state_;
};
#endif