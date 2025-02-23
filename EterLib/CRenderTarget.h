﻿#pragma once

#include <memory>
#include "GrpRenderTargetTexture.h"

class CInstanceBase;
class CGraphicImageInstance;

class CRenderTarget
{
	using TCharacterInstanceMap = std::map<DWORD, CInstanceBase*>;
	
	public:
		CRenderTarget(DWORD width, DWORD height);
		~CRenderTarget();


		void SetVisibility(bool isShow);
		void RenderTexture() const;
		void SetRenderingRect(RECT* rect) const;

		void SelectModel(DWORD index);
#ifdef RENDER_TARGED_CHARACTER_WINDOW
		void RenderPlayer();
		bool UpdatePlayerModel();
		void ZoomCamera(int direction);
		void SetModelRotation(float value);
		void SetAutoRotate(bool value);
		void SetCharacterArmor(DWORD armorID);
		void SetCharacterWeapon(DWORD weaponID);
		void SetCharacterHair(DWORD weaponID);
#endif
		bool CreateBackground(const char* imgPath, DWORD width, DWORD height);
		void RenderBackground() const;
		void UpdateModel();
		void DeformModel() const;
		void RenderModel() const;
		void SetWeapon(DWORD dwVnum);
		void SetArmor(DWORD vnum);
		void SetEffectWeapon(DWORD vnum);
		void SetEffectArmor(DWORD vnum);
		void SetEffectHair(DWORD vnum);
		void SetAcce(DWORD vnum);
		void ChangeHair(DWORD vnum);
		void CreateTextures() const;
		void ReleaseTextures() const;
	
	private:
		std::unique_ptr<CInstanceBase> m_pModel; 
		std::unique_ptr<CGraphicImageInstance> m_background;
		std::unique_ptr<CGraphicRenderTargetTexture> m_renderTargetTexture;
		float m_modelRotation;
		bool m_visible;
};
