/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:04:41 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 12:03:07 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *materias[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        virtual ~MateriaSource();

        MateriaSource &operator=(const MateriaSource &other);

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif