 ���������������������������������������������������������������������������
 ����������//////////�////////���////////��///����///�//////////�////////.��
 ���������///�������///����///�///����///�///����///�///��������///����///��
 ��������///�������///��������///��������///����///�///��������///����///���
 �������////////��//////////�///��������//////////�////////���/////////�����
 ������///��������������///�///��������///����///�///��������///���.///�����
 �����///�������///����///�///����///�///����///�///��������///����///������
 ����//////////�////////���////////��///.���///.//////////�///����///.������
 ���������������������������������������������������������������������������
 �����������Copyright�(c)�1994,�1995�by�Charybdis�Enterprises,�Inc.���������
 ��������������������������All�Rights�Reserved.�����������������������������
 ���������������������������������������������������������������������������
 ��������������������� Microsoft Windows '95 Version �����������������������
 ���������������������������������������������������������������������������
 ---------------------------------------------------------------------------
 
            *** Charybdis Enterprises, Inc. Company Confidential ***
 
   This file and all associated files are the company proprietary property
         of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
 
  CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
  TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
  IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
  AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
  INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.

 ---------------------------------------------------------------------------

  This library is a component of the MythOS(tm) entertainment and multi-
  media development library.

  MythOS is a trademark of Charybdis Enterprises, Inc.

 ---------------------------------------------------------------------------

                         *** Escher Terrain Editor ***

 Notes by: Chuck Walbourn

 Last Updated: Nov 7, 1995

 Escher Terrain Editor - MFC Application

 Changes for this release --------------------------------------------------

 o Created MFC application for editing terrain data sets.



 Pending changes -----------------------------------------------------------

 o The render view camera's location should be indicated on the
   surface grid.

 o A method for setting an area of the surface grid to a specified color
   and/or flags combination is needed for large editing changes.

 o A zoom to rectangle option would be convient.

 o Export to IFF currently exports the current lighting values.
   Option for clearing this should be included.

 o Display using the level-of-detail control should be added to the
   render view.



 Known problems ------------------------------------------------------------

 o A number of menu items are being sent messages to disable themselves
   when the render view is disabled.  Windows 95 or MFC is not properly
   setting thier new states, and they therefore remain active even while
   the render view is disabled.

   Also, the 'Perspective' render mode option is supposed to be disabled
   when 'Textures' mode is off.

 *** END OF FILE ***
