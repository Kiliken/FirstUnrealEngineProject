// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "MenuHUD.h"

/**
 * 
 */
class SInGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInGameWidget){}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	TWeakObjectPtr<class AMenuHUD> OwningHUD;
};
