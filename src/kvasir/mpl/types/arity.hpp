#pragma once

namespace kvasir{
	namespace mpl{
		namespace detail{
			template<typename T>
			using voidt = void;
		}
		/// \exclude
		template<int L, int H>
		struct arity{
			static constexpr int low = L;
			static constexpr int high = H;
		};
		/// \exclude
		template<typename T, typename=void>
		struct arity_traits{
			using type = arity<-1,-1>;  //unknown
		};
		/// \exclude
		template<typename T>
		struct arity_traits<T,detail::voidt<typename T::arity>>{
			using type = typename T::arity;
		};
}
}
