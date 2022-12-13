#pragma once

class not_implemented_exception : public std::logic_error {
public:
	not_implemented_exception(const char* error = "This function is not yet implemented.") : std::logic_error(error) {
		errorMessage = error;
	}

	const char* what() const noexcept {
		return errorMessage.c_str();
	}

private:
	std::string errorMessage;
};
