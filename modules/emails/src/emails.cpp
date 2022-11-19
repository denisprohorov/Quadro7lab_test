#include "emails/emails.h"
#include <cmath>

std::string emails::hide_email(std::string_view email) {
    size_t email_length = email.size();
    int hide_char_count = std::ceil(static_cast<float>(email_length) * hide_level);
    std::string hide_email = {email.data(), email_length - hide_char_count};
    hide_email += std::string(hide_char_count, '*');

    return hide_email;
}