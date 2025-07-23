// Fill out your copyright notice in the Description page of Project Settings.


#include "SInGameWidget.h"
#include "SlateOptMacros.h"

#define LOCTEXT_NAMESPACE "Game"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInGameWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(50.f, 50.f);

	const FString score = FString::Printf(TEXT("SCORE : %d"), OwningHUD->points);
	const FText ScoreText = FText::FromString(score);

	FSlateFontInfo ScoreTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ScoreTextStyle.Size = 60.f;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)

			//SCORE
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(ScoreTextStyle)
				.Text(ScoreText)
				.ColorAndOpacity(FColor::Black)
				.Justification(ETextJustify::Left)
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


#undef LOCTEXT_NAMESPACE
