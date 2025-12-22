#pragma once

#include <map>
#include <string>
#include <variant>

namespace Sdx::CS
{

using InitializationData = std::variant<uint32_t, int32_t, double, bool, std::string>;
using InitializationDatas = std::map<std::string, InitializationData>;

constexpr auto START_WEEK_KEY = "startWeek";
constexpr auto START_SECOND_OF_WEEK_KEY = "startSecondOfWeek";
constexpr auto PATH_TO_XML_KEY = "pathToXml";
constexpr auto XML_FILE_NAME_KEY = "xmlFileName";
constexpr auto CUSTOM_SIGNAL_NAME_KEY = "customSignalName";

constexpr auto KLOBUCHAR_ALPHA_0_KEY = "alpha0";
constexpr auto KLOBUCHAR_ALPHA_1_KEY = "alpha1";
constexpr auto KLOBUCHAR_ALPHA_2_KEY = "alpha2";
constexpr auto KLOBUCHAR_ALPHA_3_KEY = "alpha3";
constexpr auto KLOBUCHAR_BETA_0_KEY = "beta0";
constexpr auto KLOBUCHAR_BETA_1_KEY = "beta1";
constexpr auto KLOBUCHAR_BETA_2_KEY = "beta2";
constexpr auto KLOBUCHAR_BETA_3_KEY = "beta3";

constexpr auto NEQUICK_AI_0_KEY = "ai0";
constexpr auto NEQUICK_AI_1_KEY = "ai1";
constexpr auto NEQUICK_AI_2_KEY = "ai2";

constexpr auto TOT_KEY = "tot";
constexpr auto WNOT_KEY = "wnot";
constexpr auto A0_KEY = "a0";
constexpr auto A1_KEY = "a1";
constexpr auto A2_KEY = "a2";
constexpr auto DELTA_TLS_KEY = "deltaTLS";
constexpr auto WN_LSF_KEY = "wnLSF";
constexpr auto DN_KEY = "dn";
constexpr auto DELTA_TLSF_KEY = "deltaTLSF";

} // namespace Sdx::CS
