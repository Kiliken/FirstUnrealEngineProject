// Fill out your copyright notice in the Description page of Project Settings.


#include "SSMainMenuWidget.h"
#include "SlateOptMacros.h"

#define LOCTEXT_NAMESPACE "MainMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(20.f);

	const FText TitleText = LOCTEXT("GameTitle", "PAUSE");
	const FText PlayText = LOCTEXT("PlayGame", "RESUME");
	const FText QuitText = LOCTEXT("QuitGame", "QUIT");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)

			//TITLE
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(TitleTextStyle)
				.Text(TitleText)
				.Justification(ETextJustify::Center)
			]

			//PLAY BUTTON
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SMainMenuWidget::OnPlayClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(PlayText)
					.Justification(ETextJustify::Center)
				]
			]

			//QUIT BUTTON
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SMainMenuWidget::OnQuitClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(QuitText)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMainMenuWidget::OnPlayClicked() const{
	if (OwningHUD.IsValid()) {
		//OwningHUD->HideMenu();
		
		
	}

	return FReply::Handled();
}

FReply SMainMenuWidget::OnQuitClicked() const {
	if (OwningHUD.IsValid()) {
		FGenericPlatformMisc::RequestExit(false);
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
