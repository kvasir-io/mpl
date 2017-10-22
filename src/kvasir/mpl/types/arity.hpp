#pragma once

namespace kvasir{
	namespace mpl{
		namespace detail{
			template<typename T>
			using voidt = void;
		}
		template<int L, int H>
		struct arity{
			static constexpr int low = L;
			static constexpr int high = H;
		};
		template<typename T, typename=void>
		struct arity_traits{
			using type = arity<-1,-1>;  //unknown
		};
		template<typename T>
		struct arity_traits<T,detail::voidt<typename T::arity>>{
			using type = typename T::arity;
		};
}
}
