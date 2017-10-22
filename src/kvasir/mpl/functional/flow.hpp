#pragma once
#include "../compatability/dependent_call.hpp"
#include "identity.hpp"
#include "../types/arity.hpp"
namespace kvasir {
	namespace mpl {
		namespace detail{		
			template <typename A, typename P, typename TC, typename FC>
			struct if_impl {
				template <typename... Ts>
				using f = typename conditional<dcall<P,sizeof...(Ts)>::template f<Ts...>::value>::template
					 f<TC, FC>::template f<Ts...>;
			};
 			template <typename P, typename TC, typename FC>
       	        	struct if_impl<arity<1,1>,P,TC,FC> {
				template <typename T>
                        	using f = typename conditional<P::template f<T>::value>::template f<
                                                           TC, FC>::template f<T>;
                	};
		}
		template<typename P, typename TC, typename FC=identity>
		using if_ = detail::if_impl<typename arity_traits<P>::type,P,TC,FC>;
	} // namespace mpl
} // namespace kvasir
