/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:03:14 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 12:49:25 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    *this = other;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (materias[i])
                delete materias[i];
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = materia;
            std::cout << "Materia " << materia->getType() << " learned at slot " << i << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource is full, cannot learn more materias." << std::endl;
    delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
        {
            std::cout << "Materia " << type << " created from slot " << i << std::endl;
            return materias[i]->clone();
        }
    }
    std::cout << "Materia " << type << " not found in MateriaSource." << std::endl;
    return NULL;
}