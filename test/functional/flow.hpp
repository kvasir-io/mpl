#include <kvasir/mpl/mpl.hpp>
namespace {
	using namespace kvasir;
	using namespace mpl;
	static_assert(call<if_<same_as<void>, always<false_>, always<true_>>, int>::value, "");
}
