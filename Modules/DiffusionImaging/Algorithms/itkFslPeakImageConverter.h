/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkDiffusionTensor3DReconstructionImageFilter.h,v $
  Language:  C++
  Date:      $Date: 2006-03-27 17:01:06 $
  Version:   $Revision: 1.12 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkFslPeakImageConverter_h_
#define __itkFslPeakImageConverter_h_

#include <itkImageToImageFilter.h>
#include <itkVectorContainer.h>
#include <mitkFiberBundleX.h>
#include <itkOrientationDistributionFunction.h>

namespace itk{
/** \class FslPeakImageConverter
  Converts a series of 4D images containing directional (3D vector) information into a vector field stored as mitkFiberBundleX.
  These 4D files are for example generated by the FSL qboot command.
*/

template< class PixelType >
class FslPeakImageConverter : public ProcessObject
{

public:

  enum NormalizationMethods {
    NO_NORM,
    SINGLE_VEC_NORM
  };

  typedef FslPeakImageConverter Self;
  typedef SmartPointer<Self>                      Pointer;
  typedef SmartPointer<const Self>                ConstPointer;
  typedef ProcessObject Superclass;

   /** Method for creation through the object factory. */
  itkNewMacro(Self)

  /** Runtime information support. */
  itkTypeMacro(FslPeakImageConverter, ImageToImageFilter)

  typedef vnl_vector_fixed< double, 3 >                                 DirectionType;
  typedef VectorContainer< int, DirectionType >                         DirectionContainerType;
  typedef VectorContainer< int, DirectionContainerType::Pointer >       ContainerType;
  typedef Image< float, 4 >                                             InputImageType;
  typedef VectorContainer< int, InputImageType::Pointer >               InputType;
  typedef Image< Vector< float, 3 >, 3>                                 ItkDirectionImageType;
  typedef VectorContainer< int, ItkDirectionImageType::Pointer >        DirectionImageContainerType;

  itkSetMacro( NormalizationMethod, NormalizationMethods)
  itkSetMacro( InputImages, InputType::Pointer)
  itkGetMacro( OutputFiberBundle, mitk::FiberBundleX::Pointer)
  itkGetMacro( DirectionImageContainer, DirectionImageContainerType::Pointer)

  void GenerateData();

protected:
  FslPeakImageConverter();
  ~FslPeakImageConverter(){}

  NormalizationMethods                  m_NormalizationMethod;
  mitk::FiberBundleX::Pointer           m_OutputFiberBundle;
  InputType::Pointer                    m_InputImages;
  DirectionImageContainerType::Pointer  m_DirectionImageContainer;

private:

};

}

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkFslPeakImageConverter.cpp"
#endif

#endif //__itkFslPeakImageConverter_h_
